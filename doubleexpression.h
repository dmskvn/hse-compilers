#ifndef doubleexpr_h
#define doubleexpr_h

#include "expression.h"

#include <string>

class DoubleExpression : public IExpression {
public:
	DoubleExpression(double d);
	DoubleExpression(char *varName);
	virtual double value() const override;
	
private:
	double _d;
	std::string _varName;
};

#endif