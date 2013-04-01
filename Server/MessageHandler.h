
#include "ClientConnection.h"

enum MessageCode{
	CONNECTION_DOWN
};

class CMessageHandler{

public:
	CMessageHandler(CClientConnection* clientConnection, MessageCode messageCode):
				_clientConnection(clientConnection),
				_messageCode(messageCode)
				{};

	~CMessageHandler();

	MessageCode getMessageCode();
	CClientConnection* getClientConnection();

private:
	int id;

	CClientConnection* _clientConnection;
	MessageCode _messageCode;

};