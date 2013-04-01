
#include "MessageHandler.h"

CMessageHandler::~CMessageHandler(){
}

MessageCode CMessageHandler::getMessageCode(){
	return _messageCode;
}

CClientConnection* CMessageHandler::getClientConnection(){
	return _clientConnection;
}