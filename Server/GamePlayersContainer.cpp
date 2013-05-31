#include "GamePlayersContainer.h"

CGamePlayersContainer::~CGamePlayersContainer(){
	boost::lock_guard<boost::mutex> lock(_mutex);

}
void CGamePlayersContainer::insert(int id,CGamePlayer* gamePlayer){
	boost::lock_guard<boost::mutex> lock(_mutex);
	_gamePlayers.insert(std::pair<int,CGamePlayer*>(id,gamePlayer));
}

void CGamePlayersContainer::erase(int id){
	boost::lock_guard<boost::mutex> lock(_mutex);
	_gamePlayers.erase(id);
}

void CGamePlayersContainer::eraseDelete(int id){
	boost::lock_guard<boost::mutex> lock(_mutex);
	delete(_gamePlayers.at(id));
	_gamePlayers.erase(id);
}

CGamePlayer* CGamePlayersContainer::get(int id){
	boost::lock_guard<boost::mutex> lock(_mutex);
	return _gamePlayers.at(id);
}

void clear(){

}