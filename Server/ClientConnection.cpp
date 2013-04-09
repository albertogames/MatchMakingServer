#include "ClientConnection.h"


#include "MessageHandler.h"
#include "Parser.h"
#include "Handler.h"
#include "Builder.h"
#include "BaseClass.h"
#include <iterator>
#include "Constants.h"


CClientConnection::CClientConnection(){

}

CClientConnection::~CClientConnection()
{
	closeConnection();
	//Erase pointer
	_server = NULL;
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

			if (_connectionState == ClientState::LOGGED){

				analyzeMessage(message);
				strcpy_s(message, "");
			
			}else if (_connectionState == ClientState::CONNECTED){
			
				login(message);
				strcpy_s(message,"");
			
			}
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

void CClientConnection::sendMessage(std::string message)
{
	int errorCode = send(_connection,message.c_str(),sizeof(message)+2,NULL);
	
	if (errorCode == SOCKET_ERROR){
		std::cout << "ERROR ClientConnection.sendMessage : send(): " << WSAGetLastError() << std::endl;
	}

}

void CClientConnection::analyzeMessage(std::string message){
	std::cout << "Client id: " << _id << " MESSAGE: " << message << std::endl;
	
	std::list<std::string> messageParams = CParser::getSingletonPtr()->parse(message);

	if (messageParams.size() > 1){
		std::list<std::string>::iterator it = messageParams.begin();

		std::string code = *it;

		if (code.compare(Constants::COM_DISP_PLAY) == 0){

			CMessageHandler* _msj = new CMessageHandler(this,DISP_PLAY);

			_server->handler(_msj);
		}

		if (code.compare(Constants::COM_DISP_PLAY_CANCEL) == 0){
			CMessageHandler* _msj = new CMessageHandler(this,DISP_PLAY_CANCEL);

			_server->handler(_msj);
		}
	}

	//sendMessage("Serve");
}

void CClientConnection::login(std::string message){

	std::list<std::string> messageParams = CParser::getSingletonPtr()->parse(message);
	
	if (messageParams.size() == 4){

		std::list<std::string>::iterator it = messageParams.begin();
		std::string code = *it;
		it++;
		std::string user = *it;
		it++;
		std::string passwd = *it; 

		std::cout << "Code: " << code << " Client user: " << user << " passwd: " << passwd << std::endl;
		
		_userName = user;

		if (code.compare(Constants::COM_LOG) == 0){
			_connectionState = ClientState::LOGGED;
		
			sendMessage(Constants::COM_LOG_OK + Constants::PARSER_CHAR);
		}

		messageParams.clear();
	
	}
}