#include "Serializable.h"
#include <boost/lexical_cast.hpp>

void CSerializable::serializeString(std::ostream& stream, std::string cad){
		
	int tam;
	std::string aux = cad;
	tam = aux.length();
	std::string s = boost::lexical_cast<std::string>( tam );

	stream.write(s.c_str(),sizeof(tam));
		
	if (tam > 0){ 
		stream.write(aux.c_str(), tam*sizeof(char));
		printf("Se escribio %s \n",aux.c_str());
	}

}
	

std::string CSerializable::deserializeString(std::iostream& stream){
	
	int tam;
	char* tamChar;
	stream.read(tamChar,sizeof(tam));
		
	tam = boost::lexical_cast<int>(tamChar);

	if (tam > 0){
		
		char* charCad = new char [tam];
		stream.read(charCad,tam*sizeof(char));
		printf("se leyo %s \n",charCad);
		std::string stringCad (charCad);
			
		return stringCad;
	}else{
			
		return "";
		
	}	
}