#include "ClientConnection.h"

#include "ConnectionMessage.h"
#include "ConnectionMessagesProcessor.h"
#include "GameMessagesProcessor.h"

CClientConnection::~CClientConnection()
{
	closeConnection();
	//Erase pointer
	_connectionMessagesProcessor = NULL;
	_gameMessagesProcessor = NULL;
}

void CClientConnection::startThread()
{
	int errorCode;

	char message[40];

	for(;!_finish;)
	{

		errorCode = recv(_connection, message, sizeof(message), NULL);
		
		if (errorCode > 0){

			if (_gameMessagesProcessor != NULL)
				_gameMessagesProcessor->processGameMessage();

			strcpy_s(message, "");

		}
		else{
			
			if (errorCode == 0){

				std::cout << "MESSAGE ClientConnection.startThread : recv(): " << _id << " CONNECTION CLOSED " << std::endl;
			
			}else{

				std::cout << "ERROR ClientConnection.startThread : recv(): " << _id << " " << WSAGetLastError() << " CONNECTION CLOSED " << std::endl;
			
			}

			CConnectionMessage* _msj = new CConnectionMessage(this,CONNECTION_DOWN);

			_connectionMessagesProcessor->processConnectionMessage(_msj);
			
			//_finish = true;

		}
	}
}

void CClientConnection::closeConnection(){
	//Close socket
	if (_connection){
		closesocket(_connection);
		_connection = NULL;
	}
}

void CClientConnection::sendMessage(std::string message)
{
	int errorCode = send(_connection,message.c_str(),sizeof(message)+2,NULL);
	
	if (errorCode == SOCKET_ERROR){
		std::cout << "ERROR ClientConnection.sendMessage : send(): " << WSAGetLastError() << std::endl;
	}

}

void CClientConnection::setId(int id){
	_id = id;
}
