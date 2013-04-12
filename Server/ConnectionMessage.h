#ifndef __ConnectionMessage_H
#define __ConnectionMessage_H

class CClientConnection;

class CConnectionMessage{

public:
	CConnectionMessage(CClientConnection* clientConnection, ConnectionState messageCode):
						_clientConnection(clientConnection),
						_messageCode(messageCode)
						{};

	virtual ~CConnectionMessage(){};

	ConnectionState getMessageCode(){return _messageCode;};

	CClientConnection* getClientConnection(){return _clientConnection;};

private:

	ConnectionState _messageCode;

	CClientConnection* _clientConnection;
};

#endif