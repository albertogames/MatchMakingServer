#include "Serializer.h"
#include <assert.h>

CSerializer* CSerializer::_instance = 0;

CSerializer::CSerializer(void)
{

}

CSerializer::~CSerializer(void)
{
	assert(_instance);

}

bool CSerializer::Init() 
{
	assert(!_instance && "Second initialization of CSerializar not allowed!");
	_instance = new CSerializer();
	return true;
}

void CSerializer::Release()
{
	if (_instance)
		delete _instance;
	_instance = 0;
}

void CSerializer::serialize(){


}

void CSerializer::deSerialize(){


}