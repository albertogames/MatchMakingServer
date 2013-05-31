#include <string.h>
#include <iostream>

#ifndef __GamePlayer_H
#define __GamePlayer_H

class CGamePlayer
{

public:
	virtual ~CGamePlayer(){};

	CGamePlayer(std::string ip, int id, std::string user) : _ip(ip), _id(id), _user(user){};

	void setIp(std::string ip){_ip = ip;};
	std::string getIp(){return _ip;};

	void setId(int id){_id = id;};
	int getId(){return _id;};

	void setUser(std::string user){_user = user;};
	std::string getUser(){return _user;};


private:

	std::string _ip;
	int _id;
	std::string _user;
};


#endif