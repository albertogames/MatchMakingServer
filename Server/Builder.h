#include <stdio.h>
#include <iostream>
#include <string.h> 
#include <list>

#include "BaseClass.h"

#ifndef __Builder_H
#define __Builder_H

class CBuilder
{

public:

	static bool Init();

	static CBuilder *getSingletonPtr() {return _instance; }

	static void Release();

	IBaseClass buildObject(const std::list<std::string> &charsList);

private:

	CBuilder();

	virtual ~CBuilder();

	static CBuilder*_instance;

};

#endif