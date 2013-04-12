#include "ConnectionsContainer.h"
#include "ClientConnection.h"

int CConnectionsContainer::insert(CClientConnection* clientConnection){
	int id;

		if (_freePositions.size() == 0){
			id = _clientConnections.size();
		}else{
			id = _freePositions.front();
			_freePositions.pop_front();
		}

		clientConnection->setId(id);
		_clientConnections.insert(id,clientConnection);
	
		return id;
}

void CConnectionsContainer::erase(int id){

	_clientConnections.erase(id);
	_freePositions.push_back(id);

}

CClientConnection* CConnectionsContainer::get(int id){
	
	return &_clientConnections.at(id);
}

void CConnectionsContainer::run(int id){
	_clientConnections.at(id).run();
}