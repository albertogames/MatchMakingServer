#include "ConnectionsServer.h"
#include "ConnectionMessage.h"
#include "ConnectionsContainer.h"
#include "GameMessagesProcessor.h"

#include <assert.h>


void CConnectionsServer::run(){

	bool finish = false;

	_connectionsContainer = new CConnectionsContainer();

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

					id = _connectionsContainer->insert(new CClientConnection(_sConnect,this));
					
					_connectionsContainer->run(id);

					std::cout << "Client id: " << id <<" A connection was found" << std::endl;

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


void CConnectionsServer::processConnectionMessage(CConnectionMessage* connectionMessage)
{
	int id = connectionMessage->getClientConnection()->getId() ;
	std::cout << "Client: " << id << " CODE: " << connectionMessage->getMessageCode() << std::endl;
	
	switch (connectionMessage->getMessageCode()){
		
		case CONNECTION_DOWN:{

			_connectionsContainer->erase(id);

			std::cout << "Client: " << id << " desconectado "<< std::endl;
	
			break;
		
		}	

	}

	delete(connectionMessage);
}

void CConnectionsServer::processGameMessage(){

	if (_gameMessagesProcessor != NULL){
	
		_gameMessagesProcessor->processGameMessage();

	}
}
