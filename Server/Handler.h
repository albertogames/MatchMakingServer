#ifndef __Handler_H
#define __Handler_H

class CMessageHandler;

class IHandler
{
public:
	virtual void handler(CMessageHandler* message) = 0;
};

#endif