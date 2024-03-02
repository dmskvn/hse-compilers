#ifndef expr_h
#define expr_h

#include <string>

class IExpression
{
    public:

    virtual std::string type() const = 0;
    
    virtual std::string asString() const = 0;	
	virtual int asInt() const = 0;
    virtual double asDouble() const = 0;


    virtual ~IExpression() = 0;
};

#endif