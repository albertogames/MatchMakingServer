#include <assert.h>
#include "Parser.h"
#include "Builder.h"
#include <boost/tokenizer.hpp>
#include "Constants.h"


CParser *CParser::_instance = 0;

CParser::CParser(std::string character){
	_instance = this;

	_character = character;
}

CParser::~CParser(){
	assert(_instance);

	_instance = 0;
}

bool CParser::Init(std::string character){

	assert (!_instance && "Segunda inicialización del Parser no permitida");

	_instance = new CParser(character);
	
	//CBuilder::Init();

	return true;
}

void CParser::Release(){
	if (_instance)
		delete _instance;

	//CBuilder::Release();

	_instance = 0;
}

void CParser::setCharacter(std::string character){
	_character = character;
}

IBaseClass CParser::parseAndBuild(std::string message){
	


	std::list<std::string> params = parse(message);

	IBaseClass object = CBuilder::getSingletonPtr()->buildObject(params);

	return object;
 
}

std::list<std::string> CParser::parse(std::string message){

	std::list<std::string> params;

	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	boost::char_separator<char> sep(Constants::PARSER_CHAR.c_str());
	tokenizer tokens(message, sep);
	for (tokenizer::iterator tok_iter = tokens.begin()  ; tok_iter != tokens.end()  ;  ++tok_iter){
		
		params.push_back(*tok_iter);
	}

	return params;
}



