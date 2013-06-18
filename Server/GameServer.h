//Standar headers for a console application

#include <string.h>
#include <iostream>
#include <utility>
#include "GameMessagesProcessor.h"
#include "GamePlayersContainer.h"

#include <boost\container\list.hpp>
#include <boost\container\map.hpp>

#include <boost\ptr_container\ptr_map.hpp>



#ifndef __GameServer_H
#define __GameServer_H

class CConnectionsServer;
class CClientConnection;

class CGameServer : public IGameMessagesProcessor
{

public:
	virtual ~CGameServer();

	CGameServer(char* ip, int port, int maxConn);
	
	virtual void processGameMessage(char* message,int messageSize, int clientId);
	virtual void clientDisconnected(int clientId);

	void run();

private:

	void notifyExitPlayer(std::string user);

	void notifyNewPlayer(std::string user);

	void sendPlayersToNewPlayer(int clientId);

	typedef boost::container::list<int> clientConnectionsDISp_type;
	
	clientConnectionsDISp_type _clientConnectionsDISP;

	CConnectionsServer* _connectionsServer;

	boost::container::map<int,std::string> _clients;

	CGamePlayersContainer* _playersContainer;
	CGamePlayersContainer* _playersAvailable;
};


#endif