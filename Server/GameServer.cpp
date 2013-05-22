#include "GameServer.h"
#include "Serializer.h"
#include "ConnectionsServer.h"

#include "messages.pb.h"


CGameServer::CGameServer(char* ip, int port, int maxConn){
	
	_connectionsServer = new CConnectionsServer(ip,port,maxConn,this);

	_connectionsServer->run();
	
}

void CGameServer::processGameMessage(char* message, int clientId){

	
	Messages::Message msg;
	msg.ParseFromArray(message,strlen(message));
	
	Messages::Message_MessageType messageType = msg.messagetype();

	switch (messageType){
	
		//LOG
		case Messages::Message_MessageType::Message_MessageType_LOG:{


			Messages::Message* messageSend = new Messages::Message();
			messageSend->set_messagetype(Messages::Message_MessageType::Message_MessageType_LOG_OK);

			int i = messageSend->ByteSize();
			char* aux = (char*)malloc(i);
			memset(aux,0,i);
			messageSend->SerializeToArray(aux,i);
			char* aux2 = (char*)malloc(i+1);
			memset(aux2,i,i+1);
			memcpy_s(aux2 + 1,i,aux,i);
			_connectionsServer->sendMessage(i + 1,aux2, clientId);
			
			//Destruir messageSend
			delete(aux);
			delete(aux2);
			delete(messageSend);

			break;														
		}
		
		case Messages::Message_MessageType::Message_MessageType_DISP_PLAY:{

			_clientConnectionsDISP.push_back(clientId);

			sendPlayersToNewPlayer(clientId,msg.username());

			notifyNewPlayer(msg.username());

			break;
		}

		case Messages::Message_MessageType::Message_MessageType_DISP_PLAY_CANCEL:{
			
			_clientConnectionsDISP.remove(clientId);

			notifyExitPlayer(msg.username());

			break;
		}

	}
	

}

void CGameServer::notifyNewPlayer(std::string user){
	
	Messages::Message* messageSend = new Messages::Message();
	messageSend->set_messagetype(Messages::Message_MessageType_USER_AVAILABLE_PLAY);
	messageSend->set_username(user);

	clientConnectionsDISp_type::iterator it;

	int i = messageSend->ByteSize();
	char* aux = (char*)malloc(i);
	memset(aux,0,i);
	messageSend->SerializeToArray(aux,i);
	char* aux2 = (char*)malloc(i+1);
	memset(aux2,i,i+1);
	memcpy_s(aux2 + 1,i,aux,i);


	for (it = _clientConnectionsDISP.begin() ; it != _clientConnectionsDISP.end() ; it++){
		_connectionsServer->sendMessage(i + 1,aux2, (*it));
	}	

	//Destruir messageSend
	delete(aux);
	delete(aux2);

	delete(messageSend);
}

void CGameServer::notifyExitPlayer(std::string user){
	
	Messages::Message* messageSend = new Messages::Message();
	messageSend->set_messagetype(Messages::Message_MessageType_USER_AVAILABLE_PLAY_CANCEL);
	messageSend->set_username(user);

	clientConnectionsDISp_type::iterator it;

	int i = messageSend->ByteSize();
	char* aux = (char*)malloc(i);
	memset(aux,0,i);
	messageSend->SerializeToArray(aux,i);
	char* aux2 = (char*)malloc(i+1);
	memset(aux2,i,i+1);
	memcpy_s(aux2 + 1,i,aux,i);


	for (it = _clientConnectionsDISP.begin() ; it != _clientConnectionsDISP.end() ; it++){
		_connectionsServer->sendMessage(i + 1,aux2, (*it));
	}	

	//Destruir messageSend
	delete(aux);
	delete(aux2);

	delete(messageSend);
}


void CGameServer::sendPlayersToNewPlayer(int clientId, std::string user){

	clientConnectionsDISp_type::iterator it;
	Messages::Message* messageSend = new Messages::Message();
	messageSend->set_messagetype(Messages::Message_MessageType_USER_AVAILABLE_PLAY);
	

	for (it = _clientConnectionsDISP.begin() ; it != _clientConnectionsDISP.end() ; it++){
		
		messageSend->set_username(user);

		int i = messageSend->ByteSize();
		char* aux = (char*)malloc(i);
		memset(aux,0,i);
		messageSend->SerializeToArray(aux,i);
		char* aux2 = (char*)malloc(i+1);
		memset(aux2,i,i+1);
		memcpy_s(aux2 + 1,i,aux,i);
		_connectionsServer->sendMessage(i + 1,aux2, clientId);


		//Destruir messageSend
		delete(aux);
		delete(aux2);
	}

	delete(messageSend);

}

CGameServer::~CGameServer(){

}
/*
void CGameServer::sendGameMessage(CGameConnectionMessage* message)
{
	int id = message->getGameClientConnection()->getId() ;
	std::cout << "Client: " << id << " CODE: " << message->getMessageCode() << std::endl;
	
	switch (message->getMessageCode()){

		case DISP_PLAY:{
			int id = message->getClientConnection()->getId();

			_clientConnectionsDISP.push_back(message->getClientConnection());

			sendPlayersToNewPlayer(message->getClientConnection(),message->getClientConnection()->getUserName());

			notifyNewPlayer(message->getClientConnection()->getUserName());

			break;			   
		}

		case DISP_PLAY_CANCEL:{

			_clientConnectionsDISP.remove(message->getClientConnection());

			notifyExitPlayer(message->getClientConnection()->getUserName());

			break;
		}

	}

	delete(message);
}

void CGameServer::notifyExitPlayer(std::string user){
	std::string message ="";

	message += Constants::COM_DISP_PLAY_CANCEL;
	message += Constants::PARSER_CHAR;
	message += user;
	message += Constants::PARSER_CHAR;

	notifyPlayers(message,user);
}
void CGameServer::notifyNewPlayer(std::string user){
	
	std::string message ="";

	message += Constants::COM_NEW_PLAYER;
	message += Constants::PARSER_CHAR;
	message += user;
	message += Constants::PARSER_CHAR;

	notifyPlayers(message,user);	
}

void CGameServer::sendPlayersToNewPlayer(CClientConnection *client, std::string user){

	clientConnectionsDISp_type::iterator it;
	for (it = _clientConnectionsDISP.begin() ; it != _clientConnectionsDISP.end() ; it++){
		if ((*it)->getUserName().compare(user) != 0){
			std::string message ="";

			message += Constants::COM_NEW_PLAYER;
			message += Constants::PARSER_CHAR;
			message += (*it)->getUserName();
			message += Constants::PARSER_CHAR;

			client->sendMessage(message);
		}
	}

}

 void CGameServer::notifyPlayers(std::string message, std::string user){

	clientConnectionsDISp_type::iterator it;
	for (it = _clientConnectionsDISP.begin() ; it != _clientConnectionsDISP.end() ; it++){
		if ((*it)->getUserName().compare(user) != 0){
			(*it)->sendMessage(message);
		}
	}

 }*/