#include "GameServer.h"
//#include "GameConnectionMessage.h"


CGameServer::CGameServer(char* ip, int port, int maxConn){
	
	_connectionsServer = new CConnectionsServer(ip,port,maxConn,this);

}

void CGameServer::processGameMessage(){


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