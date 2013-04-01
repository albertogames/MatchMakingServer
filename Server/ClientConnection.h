
#ifndef __ClientConnection_H
#define __ClientConnection_H

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>

#include "Thread.h"

#include <boost\thread.hpp>

class CServer;
class IHandler;
class CMessageHandler;

class CClientConnection: public IThread
{
public:
	CClientConnection();

	virtual ~CClientConnection();

	CClientConnection(SOCKET connection, IHandler* server,int id): 
				_connection(connection),
				_server(server),
				_id(id){};

	int getId();

	void setId(int id);

	void sendMessage(char* message);
private:

	void closeConnection();

	virtual void startThread();
	
	void analyzeMessage(char* message);

	int _id;

	IHandler* _server;

	SOCKET _connection;
};

#endif