#include "Server.h"
#include "ClientConnection.h"
#include "MessageHandler.h"

CServer::~CServer(){
}

void CServer::run(){
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

	}

	delete(message);
}
