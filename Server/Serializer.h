#ifndef __Serializer_H
#define __Serializer_H

class CSerializer{

public:

	static CSerializer* getSingletonPtr(){return _instance;};

	static bool Init();
	
	static void Release();

	void serialize();

	void deSerialize();

private:
	
	CSerializer();

	virtual ~CSerializer();

	static CSerializer* _instance;

};

#endif 