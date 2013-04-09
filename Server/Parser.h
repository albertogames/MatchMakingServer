
#include <conio.h>
#include <stdio.h>
#include <string.h> 
#include <iostream>
#include <list>
#include "BaseClass.h"


#ifndef __Parser_H
#define __Parser_H

class CParser
{

	

public:
	
	static bool Init(std::string character);

	static CParser *getSingletonPtr() {return _instance; }

	static void Release();

	IBaseClass parseAndBuild(std::string message);

	std::list<std::string> parse(std::string message);

	void setCharacter(std::string character);

private:

	CParser(std::string character);

	virtual ~CParser();

	static CParser*_instance;
	
	std::string _character;
};

#endif