//Link a library to our project
#pragma comment(lib,"Ws2_32.lib")

//Standar headers for a console application

#ifndef __ConnectionsServer_H
#define __ConnectionsServer_H

#include <sdkddkver.h>
#include <conio.h>
#include <stdio.h>
#include <string.h> 
#include <list>

#include <assert.h> 

//Specified headers
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>

#include "ConnectionMessagesProcessor.h"
#include "ConnectionsContainer.h"
#include "MessagesProcessor.h"

#include <boost\thread\thread.hpp>

#include <boost\container\list.hpp>
#include <boost\ptr_container\ptr_map.hpp>

class CMEssageHandler;
class CConnectionsContainer;
class CClientConnection;
class IGameMessagesProcessor;

class CConnectionsServer : public IConnectionMessagesProcessor, public IMessagesProcessor
{

public:

	CConnectionsServer(){};

	virtual ~CConnectionsServer(){};

	CConnectionsServer(char* ip, int port, int maxConn):_ip(ip),
			_port(port),
			_maxConn(maxConn),
			_dllVersion(MAKEWORD(2,1)),
			_addrLenght(sizeof(_addr)),
			_af(AF_INET),
			_type(SOCK_STREAM),
			_protocol(IPPROTO_TCP),
			_bOptVal(TRUE),
			_bOptLen(sizeof(_bOptVal)),
			_initDllResponse(WSAStartup(_dllVersion, &_wsaData)),
			_numConn(0),
			_gameMessagesProcessor(NULL)
			{
			};

	CConnectionsServer(char* ip, int port, int maxConn, IGameMessagesProcessor* gameMessagesProcessor):_ip(ip),
			_port(port),
			_maxConn(maxConn),
			_dllVersion(MAKEWORD(2,1)),
			_addrLenght(sizeof(_addr)),
			_af(AF_INET),
			_type(SOCK_STREAM),
			_protocol(IPPROTO_TCP),
			_bOptVal(TRUE),
			_bOptLen(sizeof(_bOptVal)),
			_initDllResponse(WSAStartup(_dllVersion, &_wsaData)),
			_numConn(0),
			_gameMessagesProcessor(gameMessagesProcessor)
			{
			};



	virtual void processConnectionMessage(CConnectionMessage* connectionMessage);
	virtual void processMessage(char* message, CClientConnection* _clientConnection);
	virtual void sendMessage(const char* message, int clientId);

	void run();
	
private:


	WSAData _wsaData;
	WORD _dllVersion;
	long _initDllResponse;

	//socket wich is listening for an incoming connection
	SOCKET _listen;


	//structure for our sockets
	SOCKADDR_IN _addr;
	int _addrLenght;

	bool _bOptVal;
	int _bOptLen;
	//general setup
	char* _ip;
	int _port;

	//socket setup
	int _af;
	int _type;
	int _protocol;

	int _maxConn;
	int _numConn;

	boost::thread* _thread;

	SOCKET _sConnect;
	char message[200];
	std::string strmessage;

	IGameMessagesProcessor* _gameMessagesProcessor;

	CConnectionsContainer* _connectionsContainer;

};


#endif