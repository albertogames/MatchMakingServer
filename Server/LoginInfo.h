#ifndef __LoginInfo_H
#define __LoginInfo_H

#include <stdio.h>
#include <string.h> 
#include "BaseClass.h"

class LoginInfo: IBaseClass{

public:

	LoginInfo(std::string user, std::string passwd):
			_user(user),
			_passwd(passwd){};

	~LoginInfo();

	std::string getUser(){return _user;}

	std::string getPasswd(){return _passwd;}

private:

	std::string _user;
	std::string _passwd;

}

#endif