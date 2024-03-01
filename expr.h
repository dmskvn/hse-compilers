#pragma once

#include <string>

class IExpression
{
    public:

    virtual std::string type() const = 0;
    
    virtual std::string asString() const = 0;	
	virtual int asInt() override const = 0;
    virtual double asDouble() override const = 0;


    virtual ~IExpression() = 0;
};