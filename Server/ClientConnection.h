
#ifndef __ClientConnection_H
#define __ClientConnection_H

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "Thread.h"

#include <boost\thread.hpp>

class IConnectionMessagesProcessor;
class IMessagesProcessor;

enum ConnectionState{
		CONNECTED,
		CONNECTION_DOWN
	};


class CClientConnection: public IThread
{	

public:
	CClientConnection(){};

	virtual ~CClientConnection();

	CClientConnection(SOCKET connection, IConnectionMessagesProcessor* connectionMessagesProcessor,int id): 
				_connection(connection),
				_connectionMessagesProcessor(connectionMessagesProcessor),
				_connectionState(CONNECTED),
				_messagesProcessor(NULL),
				_id(id){};

	CClientConnection(SOCKET connection, IConnectionMessagesProcessor* connectionMessagesProcessor):
				_connection(connection),
				_connectionMessagesProcessor(connectionMessagesProcessor),
				_connectionState(CONNECTED),
				_messagesProcessor(NULL)
				{};

	CClientConnection(SOCKET connection, IConnectionMessagesProcessor* connectionMessagesProcessor, IMessagesProcessor* messagesProcessor, int id): 
				_connection(connection),
				_connectionMessagesProcessor(connectionMessagesProcessor),
				_connectionState(CONNECTED),
				_messagesProcessor(messagesProcessor),
				_id(id){};

	CClientConnection(SOCKET connection, IConnectionMessagesProcessor* connectionMessagesProcessor, IMessagesProcessor* messagesProcessor):
				_connection(connection),
				_connectionMessagesProcessor(connectionMessagesProcessor),
				_connectionState(CONNECTED),
				_messagesProcessor(messagesProcessor)
				{};

	int getId() {return _id;}

	void setId(int id);

	void sendMessage(int size, const char* message);

	ConnectionState getConnectionState(){ return _connectionState; }

private:

	void closeConnection();

	virtual void startThread();

	int _id;

	IConnectionMessagesProcessor* _connectionMessagesProcessor;

	IMessagesProcessor* _messagesProcessor;

	SOCKET _connection;

	ConnectionState _connectionState;

	
};

#endif