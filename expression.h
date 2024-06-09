#ifndef expr_h
#define expr_h

#include <string>

class IExpression
{
public:
	virtual double value() const = 0;
	virtual std::string getCalculationExpr() const = 0;
};

#endif