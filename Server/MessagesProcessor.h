#ifndef __MessagesProcessor_H
#define __MessagesProcessor_H

class CClientConnection;

class IMessagesProcessor{

public:
	virtual void processMessage(char* message,int messageSize, CClientConnection* clientConnection) = 0;
	virtual void sendMessage(int size,const char* message, int clientId) = 0;
};

#endif 