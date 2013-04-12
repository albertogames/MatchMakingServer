#ifndef __ClientConnectionHandler_H
#define __ClientConnectionHandler_H

class CConnectionMessage;

class IConnectionMessagesProcessor
{
public:
	virtual void processConnectionMessage(CConnectionMessage* connectionMessage) = 0;
};

#endif