#ifndef double_h
#define double_h

#include "expr.h"

class Double : public IExpression {
public:

	Double(const char* name, double d);

	virtual std::string type() const override;	

	virtual std::string asString() const override;	
	virtual int asInt() const override;
    virtual double asDouble() const override;
	
private:
	
	std::string _name;
	double _d;
};

#endif