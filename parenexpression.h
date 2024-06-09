#ifndef parenexpression_h
#define parenexpression_h

#include <string>

#include "expression.h"
#include "doubleexpression.h"

class ParenExpression : public IExpression {
public:

	ParenExpression(IExpression *expr);
	double value() const override;
	virtual std::string getCalculationExpr() const override;

private:

	IExpression *_expr;
};

#endif