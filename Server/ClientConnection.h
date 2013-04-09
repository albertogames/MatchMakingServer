
#ifndef __ClientConnection_H
#define __ClientConnection_H

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "Thread.h"

#include <boost\thread.hpp>

class CServer;
class IHandler;
class CMessageHandler;

enum ClientState{
		CONNECTION_DOWN,
		CONNECTED,
		LOGGED,
		PLAYING,
		DISP_PLAY,
		DISP_PLAY_CANCEL
	};


class CClientConnection: public IThread
{	

public:
	CClientConnection();

	virtual ~CClientConnection();

	CClientConnection(SOCKET connection, IHandler* server,int id): 
				_connection(connection),
				_server(server),
				_connectionState(CONNECTED),
				_id(id){};

	int getId() {return _id;}

	void setId(int id);

	void sendMessage(std::string message);

	ClientState getConnectionState(){ return _connectionState; }
	
	std::string getUserName(){return _userName;}

private:

	void closeConnection();

	virtual void startThread();
	
	void analyzeMessage(std::string message);
	void login(std::string message);

	int _id;

	IHandler* _server;

	SOCKET _connection;

	ClientState _connectionState;

	std::string _userName;

	
};

#endif