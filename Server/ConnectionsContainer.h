#include <boost\container\list.hpp>
#include <boost\ptr_container\ptr_map.hpp>

#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>

#include "ClientConnection.h"

#ifndef __ConnectionsContainer_H
#define __ConnectionsContainer_H

class CConnectionsContainer{

public:

	CConnectionsContainer(){};

	virtual ~CConnectionsContainer(){};

	int insert(CClientConnection* clientConnection);

	void erase(int id);

	CClientConnection* get(int id);

	void run(int it);


private:

	typedef boost::ptr_map<int, CClientConnection> clientConnections_type;
	clientConnections_type _clientConnections;

	boost::container::list<int> _freePositions;

	boost::mutex _mutex;

};


#endif