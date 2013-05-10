#include "ConnectionsContainer.h"
#include "ClientConnection.h"

int CConnectionsContainer::insert(CClientConnection* clientConnection){
	int id;
		
	boost::lock_guard<boost::mutex> lock(_mutex);

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
	boost::lock_guard<boost::mutex> lock(_mutex);

	_clientConnections.erase(id);
	_freePositions.push_back(id);

}

CClientConnection* CConnectionsContainer::get(int id){
	boost::lock_guard<boost::mutex> lock(_mutex);
	return &_clientConnections.at(id);
}

void CConnectionsContainer::run(int id){
	boost::lock_guard<boost::mutex> lock(_mutex);
	_clientConnections.at(id).run();
}