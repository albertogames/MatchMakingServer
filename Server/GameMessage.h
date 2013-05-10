#include "Serializable.h"

#ifndef __GameMessage_H
#define __GameMessage_H


enum GameState{
	DISP_PLAY,
	DISP_PLAY_CANCEL,
	LOG_OK,
	LOG,
	NEW_PLAYER_DISP_PLAY,
	NEW_PLAYER_DISP_PLAY_CANCEL
};

class CGameMessage: public CSerializable{

public:
	CGameMessage(GameState messageCode):
						_messageCode(messageCode)
						{};

	virtual ~CGameMessage(){};

	GameState getMessageCode(){return _messageCode;};

	virtual void serialize(std::ostream& stream);

	virtual void deserialize(std::iostream& stream);

private:

	GameState _messageCode;

	CSerializable* _messageContain;

};

#endif