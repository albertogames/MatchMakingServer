#ifndef __BaseClass_H
#define __BaseClass_H

class IBaseClass{


	enum MessageCode{
		DISP_Q,
		DISP_R,
		LOG,
		LOG_OK,
		LOG_ER
	};


public:
	void setMessageCode(MessageCode messageCode){ _messageCode = messageCode;}
	MessageCode getMessageCode(){return _messageCode;}


private:

	MessageCode _messageCode;

};

#endif