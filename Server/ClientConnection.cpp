#include "ClientConnection.h"

#include "ConnectionMessage.h"
#include "ConnectionMessagesProcessor.h"
#include "MessagesProcessor.h"
#include <iostream>
#include <sstream>
#include <fstream>

#include <boost/lexical_cast.hpp>

CClientConnection::~CClientConnection()
{
	closeConnection();
	//Erase pointer
	_connectionMessagesProcessor = NULL;
	_messagesProcessor = NULL;
}

void CClientConnection::startThread()
{
	int errorCode;
	
	//std::istringstream stream;
	char* message = new char[40];
	int bytesReceived;
	int bytesInBuffer = 0;
	int messageSize = 0;
	char *buffer;
	int messageBytesLeft = 0;
	int offSet = 0;
	for(;!_finish;)
	{
		
		bytesReceived = recv(_connection, message, strlen(message), NULL);
		
		offSet = 0;
		
		if (bytesReceived > 0){

			if (messageBytesLeft > 0){

				if (messageBytesLeft >= bytesReceived){

					memcpy_s((buffer+ messageSize - messageBytesLeft),messageSize,message,bytesReceived);
					messageBytesLeft -= bytesReceived;
					
					bytesReceived = 0;

				}else{

					memcpy_s((buffer+ messageSize - messageBytesLeft),messageSize,message,messageBytesLeft);

					//ENVIAR EL MENSAJE
					if (_messagesProcessor != NULL){
						_messagesProcessor->processMessage(buffer, this);
					}

					delete(buffer);

					bytesReceived -= messageBytesLeft;
					
					offSet = messageBytesLeft;
					
					messageBytesLeft = 0;
				}

			}

			for(; ((messageBytesLeft == 0 )&& (bytesReceived > 0));){

				messageSize = *(message + offSet);

				buffer = (char*) malloc(messageSize);
				memset(buffer,0,messageSize);

				//Partial message received
				if (messageSize > bytesReceived -1){
					
					//Extract the size of the message
					memcpy(buffer,message+1+offSet,bytesReceived-1);
					
					//Calculate the bytes that are needed to complete the message
					messageBytesLeft += messageSize - (bytesReceived - 1);  

				//All message Received 
				}else if (messageSize <= bytesReceived -1){

					memcpy(buffer, message+1+offSet, messageSize);

					if (_messagesProcessor != NULL){
						_messagesProcessor->processMessage(buffer, this);
					}
					delete(buffer);

					strcpy(buffer,"");
							
					bytesReceived -= messageSize + 1;

					messageBytesLeft = 0;

					//If has receive a complete message and more data
					if (bytesReceived > 0){
						offSet += messageSize + 1;
						
					}
				}
			}
		}
		else{
			
			if (bytesReceived == 0){

				std::cout << "MESSAGE ClientConnection.startThread : recv(): " << _id << " CONNECTION CLOSED " << std::endl;
			
			}else{

				std::cout << "ERROR ClientConnection.startThread : recv(): " << _id << " " << WSAGetLastError() << " CONNECTION CLOSED " << std::endl;
			
			}

			_finish = true;

			CConnectionMessage* _msj = new CConnectionMessage(this,CONNECTION_DOWN);

			_connectionMessagesProcessor->processConnectionMessage(_msj);
			
			

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

void CClientConnection::sendMessage(int size, const char* message)
{

	int errorCode = send(_connection,message,size,NULL);

	if (errorCode == SOCKET_ERROR){
		std::cout << "ERROR ClientConnection.sendMessage : send(): " << WSAGetLastError() << std::endl;
	}

}

void CClientConnection::setId(int id){
	_id = id;
}
