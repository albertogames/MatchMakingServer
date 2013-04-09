
#include "MessageHandler.h"

CMessageHandler::~CMessageHandler(){
}

ClientState CMessageHandler::getMessageCode(){
	return _messageCode;
}

CClientConnection* CMessageHandler::getClientConnection(){
	return _clientConnection;
}