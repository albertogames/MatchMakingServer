#include "GameServer.h"
#include "Serializer.h"
#include "ConnectionsServer.h"

#include "messages.pb.h"


CGameServer::CGameServer(char* ip, int port, int maxConn){
	
	_playersContainer = new CGamePlayersContainer();

	_connectionsServer = new CConnectionsServer(ip,port,maxConn,this);
	_connectionsServer->run();
	
}

void CGameServer::processGameMessage(char* message,int messageSize, int clientId){

	
	Messages::Message msg;
	msg.ParseFromArray(message,messageSize);
	
	Messages::Message_MessageType messageType = msg.messagetype();

	switch (messageType){
	
		//LOG
		case Messages::Message_MessageType::Message_MessageType_LOG:{

			Messages::Message* messageSend = new Messages::Message();
			messageSend->set_messagetype(Messages::Message_MessageType::Message_MessageType_LOG_OK);
			messageSend->set_connectionid(clientId);

			CGamePlayer* gp = new CGamePlayer(msg.login().ip(),clientId,msg.login().username());
	
			_playersContainer->insert(clientId,gp);

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

			sendPlayersToNewPlayer(clientId);

			notifyNewPlayer(msg.username());

			break;
		}

		case Messages::Message_MessageType::Message_MessageType_DISP_PLAY_CANCEL:{
			
			_clientConnectionsDISP.remove(clientId);

			notifyExitPlayer(msg.username());

			break;
		}
		
		case Messages::Message_MessageType::Message_MessageType_PLAY_REQUEST:{
			
			Messages::Message* messageSend = new Messages::Message();
			messageSend->set_messagetype(Messages::Message_MessageType::Message_MessageType_PLAY_REQUEST);
			messageSend->set_username(msg.username());

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




	}
	

}

void CGameServer::clientDisconnected(int clientId){
	CGamePlayer* gp = _playersContainer->get(clientId);
	std::string user = _playersContainer->get(clientId)->getUser();
	
	_clientConnectionsDISP.remove(clientId);
			
	_playersContainer->eraseDelete(clientId);

	notifyExitPlayer(user);
	
}

void CGameServer::notifyNewPlayer(std::string user){
	
	std::cout << "NOTIFY NEW PLAYER: " << user << "\n";
	
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
		
		std::cout << "NOTIFY "<< user  << " to " << *it << ":" << _playersContainer->get(*it)->getUser()  << "\n";
		
		_connectionsServer->sendMessage(i + 1,aux2, (*it));
	}	

	//Destruir messageSend
	delete(aux);
	delete(aux2);

	delete(messageSend);
}

void CGameServer::notifyExitPlayer(std::string user){
	
	std::cout << "NOTIFY EXIT PLAYER: " << user << "\n";
	
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
		
		std::cout << "NOTIFY "<< user  << " to " << *it << ":" << _playersContainer->get(*it)->getUser() << "\n";
		
		_connectionsServer->sendMessage(i + 1,aux2, (*it));
	}	

	//Destruir messageSend
	delete(aux);
	delete(aux2);

	delete(messageSend);
}


void CGameServer::sendPlayersToNewPlayer(int clientId){
	
	std::cout << "SEND PLAYERS TO NEW PLAYER: " << clientId;
	
	clientConnectionsDISp_type::iterator it;
	Messages::Message* messageSend = new Messages::Message();
	messageSend->set_messagetype(Messages::Message_MessageType_USER_AVAILABLE_PLAY);
	

	for (it = _clientConnectionsDISP.begin() ; it != _clientConnectionsDISP.end() ; it++){
	
		std::cout << "SEND PLAYER: " << *it << ":" << _playersContainer->get(*it)->getUser() << " to " << clientId << "\n"; 

		messageSend->set_username(_playersContainer->get(*it)->getUser());
		messageSend->set_connectionid(*it);


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