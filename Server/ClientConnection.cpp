#include "ClientConnection.h"

#include "Handler.h"
#include "MessageHandler.h"

CClientConnection::CClientConnection(){

}

CClientConnection::~CClientConnection()
{
	closeConnection();
	//Erase pointer
	_server = NULL;
}

int CClientConnection::getId(){
	return _id;
}

void CClientConnection::startThread()
{
	bool finish;
	int errorCode;

	finish = false;

	char message[40];


	for(;!finish;)
	{
	
		

		errorCode = recv(_connection, message, sizeof(message), NULL);
		
		if (errorCode > 0){

			analyzeMessage(message);
			strcpy_s(message, "");
		}
		else{
			
			if (errorCode == 0){

				std::cout << "MESSAGE ClientConnection.startThread : recv(): " << _id << " CONNECTION CLOSED " << std::endl;
			
			}else{

				std::cout << "ERROR ClientConnection.startThread : recv(): " << _id << " " << WSAGetLastError() << " CONNECTION CLOSED " << std::endl;
			
			}

			CMessageHandler* _msj = new CMessageHandler(this,CONNECTION_DOWN);
			
			closeConnection();

			_server->handler(_msj);

			finish = true;

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

void CClientConnection::sendMessage(char* message)
{
	int errorCode = send(_connection,"Hello Client",13,NULL);

	if (errorCode == SOCKET_ERROR){
		std::cout << "ERROR ClientConnection.sendMessage : send(): " << WSAGetLastError() << std::endl;
	}
}

void CClientConnection::analyzeMessage(char* message){
	std::cout << "Client id: " << _id << " MESSAGE: " << message << std::endl;
}