#pragma once

#include "expr.h"

class Double : public IExpression {
public:

	Double(const char* name, double d);

	virtual std::string type() override const;	

	virtual std::string asString() override const;	
	virtual int asInt() override const;
    virtual double asDouble() override const;
	
private:
	
	std::string _name;
	double _d;
};