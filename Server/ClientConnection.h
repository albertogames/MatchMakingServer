
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
class IGameMessagesProcessor;

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
				_gameMessagesProcessor(NULL),
				_id(id){};

	CClientConnection(SOCKET connection, IConnectionMessagesProcessor* connectionMessagesProcessor):
				_connection(connection),
				_connectionMessagesProcessor(connectionMessagesProcessor),
				_connectionState(CONNECTED),
				_gameMessagesProcessor(NULL)
				{};

	CClientConnection(SOCKET connection, IConnectionMessagesProcessor* connectionMessagesProcessor, IGameMessagesProcessor* gameMessagesProcessor, int id): 
				_connection(connection),
				_connectionMessagesProcessor(connectionMessagesProcessor),
				_connectionState(CONNECTED),
				_gameMessagesProcessor(gameMessagesProcessor),
				_id(id){};

	CClientConnection(SOCKET connection, IConnectionMessagesProcessor* connectionMessagesProcessor, IGameMessagesProcessor* gameMessagesProcessor):
				_connection(connection),
				_connectionMessagesProcessor(connectionMessagesProcessor),
				_connectionState(CONNECTED),
				_gameMessagesProcessor(gameMessagesProcessor)
				{};

	int getId() {return _id;}

	void setId(int id);

	void sendMessage(std::string message);

	ConnectionState getConnectionState(){ return _connectionState; }

private:

	void closeConnection();

	virtual void startThread();

	int _id;

	IConnectionMessagesProcessor* _connectionMessagesProcessor;

	IGameMessagesProcessor* _gameMessagesProcessor;

	SOCKET _connection;

	ConnectionState _connectionState;

	
};

#endif