//Link a library to our project
#pragma comment(lib,"Ws2_32.lib")

//Standar headers for a console application

#ifndef __Server_H
#define __Server_H

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

#include "Handler.h"
#include "ClientConnection.h"

#include <boost\thread\thread.hpp>

#include <boost\container\list.hpp>
#include <boost\ptr_container\ptr_map.hpp>


class CMEssageHandler;

class CServer : public IHandler
{

public:
	virtual ~CServer();

	CServer(char* ip, int port, int maxConn):_ip(ip),
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
			_numConn(0)
			{
			};


	virtual void handler(CMessageHandler* message);

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
	
	boost::ptr_map<int, CClientConnection> _clientConnections;
	boost::container::list<int> _freePositions;
};


#endif