#ifndef __GameMessageProcessor_H
#define __GameMessageProcessor_H

class IGameMessagesProcessor{

public:
	virtual void processGameMessage(char* message,int messageSize, int clientId) = 0;
	virtual void clientDisconnected(int clientId) = 0;
};

#endif 