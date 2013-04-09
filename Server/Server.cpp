#include "Server.h"
#include "ClientConnection.h"
#include "MessageHandler.h"
#include "Parser.h"
#include "Constants.h"

#include <assert.h>

#include <boost/foreach.hpp>

CServer::~CServer(){
}

void CServer::run(){

	//Init parser class
	assert(CParser::Init(":") && "Error al inicializar Parser");

	bool finish;
	finish = false;

	_addr.sin_addr.s_addr = inet_addr(_ip);

	//retype the family
	_addr.sin_family = _af;

	//setup the port in the structure
	_addr.sin_port = htons(_port);

	_listen = socket(_af,_type,_protocol);

	//Use Exclusive addr
    int bOptLen = sizeof(_bOptVal);
    if (setsockopt(_listen, SOL_SOCKET, SO_EXCLUSIVEADDRUSE, 
		(char*)&_bOptVal, _bOptLen) != SOCKET_ERROR) {
         std::cout << "Set SO_EXCLUSIVEADDRUSE: ON\n";
       }

	//Bind the socket
	//Say that the socket has the IP 127.0.0.1 and the port 1234
	int error = bind(_listen, (SOCKADDR*)&_addr, sizeof(_addr));
	int id;

	if (error != SOCKET_ERROR){

		//Say that the socket is listening for an incoming connection
		listen(_listen, SOMAXCONN);

		for(;!finish;)
		{

			if (_sConnect = accept(_listen, (SOCKADDR*)&_addr,&_addrLenght))
			{	
				if (_sConnect != INVALID_SOCKET){
					
					
					
					if (_freePositions.size() == 0){

						id = _clientConnections.size();

						_clientConnections.insert(_numConn, new CClientConnection(_sConnect,this,id));
						
						_clientConnections[id].run();

						

					}else{
						
						id = _freePositions.front();
						
						_clientConnections.insert(id, new CClientConnection(_sConnect,this,id));

						_clientConnections[id].run();

						_freePositions.pop_front();
					}

					std::cout << "Client id: " << id <<" A connection was found" << std::endl;

					_numConn++;

				}else{
			
					std::cout << "ERROR Server.run - accept(): " << WSAGetLastError() << std::endl;
					finish = true;
				}
			}


		}

	}else{
		std::cout << "ERROR Server.run - bind(): " <<  WSAGetLastError() << std::endl;
	
	}
	
}


void CServer::handler(CMessageHandler* message)
{
	int id = message->getClientConnection()->getId() ;
	std::cout << "Client: " << id << " CODE: " << message->getMessageCode() << std::endl;
	
	switch (message->getMessageCode()){
		
		case CONNECTION_DOWN:{

			//_clientConnections.erase(_clientConnections.begin() + id);
			//delete(message->getClientConnection());
			_clientConnections.erase((int) id);
			_freePositions.push_back(id);
			_numConn--;
			std::cout << "Client: " << id << " desconectado "<< std::endl;
	
			break;
		
		}	

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

void CServer::notifyExitPlayer(std::string user){
	std::string message ="";

	message += Constants::COM_DISP_PLAY_CANCEL;
	message += Constants::PARSER_CHAR;
	message += user;
	message += Constants::PARSER_CHAR;

	notifyPlayers(message,user);
}
void CServer::notifyNewPlayer(std::string user){
	
	std::string message ="";

	message += Constants::COM_NEW_PLAYER;
	message += Constants::PARSER_CHAR;
	message += user;
	message += Constants::PARSER_CHAR;

	notifyPlayers(message,user);	
}

void CServer::sendPlayersToNewPlayer(CClientConnection *client, std::string user){

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

 void CServer::notifyPlayers(std::string message, std::string user){

	clientConnectionsDISp_type::iterator it;
	for (it = _clientConnectionsDISP.begin() ; it != _clientConnectionsDISP.end() ; it++){
		if ((*it)->getUserName().compare(user) != 0){
			(*it)->sendMessage(message);
		}
	}

 }