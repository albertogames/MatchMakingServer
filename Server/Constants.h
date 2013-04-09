#include <string.h>
#include <stdio.h>
#include <iostream>

#ifndef __Constants_H
#define __Constants_H

class Constants{

public:
	static std::string const COM_DISP_Q;
	static std::string const COM_DIPS_R;
	static std::string const COM_LOG;
	static std::string const COM_LOG_OK;
	static std::string const COM_LOG_ER;

	static std::string const COM_NEW_PLAYER;

	static std::string const COM_DISP_PLAY;
	static std::string const COM_DISP_PLAY_CANCEL;

	static std::string const PARSER_CHAR;
};

#endif