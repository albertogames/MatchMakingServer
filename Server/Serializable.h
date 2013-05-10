#include <boost/iostreams/stream.hpp>
#ifndef __Serializable_H
#define __Serializable_H

class CSerializable{
public:

    CSerializable(){}

    virtual ~CSerializable(){}

	virtual void serialize(std::ostream& stream) = 0;

	virtual void deSerialize(std::iostream& stream) = 0;

protected:


	void serializeString(std::ostream& stream,std::string cad);

	std::string deserializeString(std::iostream& stream);
};

#endif 