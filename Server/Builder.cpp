#include <assert.h>
#include "Builder.h"
#include "BaseClass.h"



CBuilder *CBuilder::_instance = 0;

CBuilder::CBuilder(){
	_instance = this;
}

CBuilder::~CBuilder(){
	assert(_instance);

	_instance = 0;
}

bool CBuilder::Init(){

	assert (!_instance && "Segunda inicialización del Builder no permitida");

	_instance = new CBuilder();

	return true;
}

void CBuilder::Release(){
	if (_instance)
		delete _instance;

	_instance = 0;
}

IBaseClass CBuilder::buildObject(const std::list<std::string> &charsList){
	IBaseClass o;
	return o;
}
