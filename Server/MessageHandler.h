
#include "ClientConnection.h"


class CMessageHandler{

public:
	CMessageHandler(CClientConnection* clientConnection, ClientState messageCode):
				_clientConnection(clientConnection),
				_messageCode(messageCode)
				{};

	~CMessageHandler();

	ClientState getMessageCode();
	CClientConnection* getClientConnection();

private:
	int id;

	CClientConnection* _clientConnection;
	ClientState _messageCode;

};