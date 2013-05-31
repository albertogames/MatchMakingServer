#include <boost\container\map.hpp>
#include <boost\ptr_container\ptr_map.hpp>

#include <boost\shared_ptr.hpp>

#include "GamePlayer.h"

#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>


#ifndef __GamePlayersContainer_H
#define __GamePlayersContainer_H

class CGamePlayersContainer{

public:

	CGamePlayersContainer(){};

	virtual ~CGamePlayersContainer();

	void insert(int id,CGamePlayer* gamePlayer);

	void erase(int id);

	void eraseDelete(int id);

	CGamePlayer* get(int id);

	void clear();

private:

	//typedef boost::shared_ptr<CGamePlayer> _gamePlayerShPtr_type;
	//typedef boost
		//<int, boost::shared_ptr<CGamePlayer>> _gamePlayersContainer_type;
	
	//_gamePlayersContainer_type _gamePlayers;

	boost::container::map<int, CGamePlayer*> _gamePlayers;

	boost::mutex _mutex;

};


#endif