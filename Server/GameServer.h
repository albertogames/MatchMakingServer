//Standar headers for a console application

#ifndef __GameServer_H
#define __GameServer_H

#include "ConnectionsServer.h"
#include "GameMessagesProcessor.h"

class CGameConnectionMessage;
class CConnectionsServer;

class CGameServer : public IGameMessagesProcessor
{

public:
	virtual ~CGameServer(){};

	CGameServer(char* ip, int port, int maxConn);
	
	virtual void processGameMessage();

private:

	void notifyExitPlayer(std::string user);

	void notifyNewPlayer(std::string user);

	void notifyPlayers(std::string message, std::string user);

	void sendPlayersToNewPlayer(CClientConnection *client, std::string user);

	typedef boost::container::list<CClientConnection*> clientConnectionsDISp_type;
	
	clientConnectionsDISp_type _clientConnectionsDISP;

	CConnectionsServer* _connectionsServer;

};


#endif