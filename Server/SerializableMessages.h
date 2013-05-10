#include <conio.h>
#include <stdio.h>
#include <iostream>

#include "Serializable.h"


struct Login: public CSerializable{
	std::string username;
	std::string password;

	virtual void deSerialize(std::iostream& stream){
		username = deserializeString(stream);
		password = deserializeString(stream);
	}
};

struct UserDisp: public CSerializable{
	std::string username;
};

struct UserDispCancel: public CSerializable{
	std::string username;
};

struct NewUserDisp: public CSerializable{
	std::string username;

	virtual void serialize(std::ostream& stream){
	}
};

struct NewUserDispCancel: public CSerializable{
	std::string username;

	virtual void serialize(std::ostream& stream){
	
	}
};

	