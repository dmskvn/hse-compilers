#ifndef operatorexpr_h
#define operatorexpr_h

#include "expression.h"

class OperatorExpression : public IExpression {
public:

	OperatorExpression(IExpression *lhs, IExpression *rhs, char op);			
	double value() const;
	virtual std::string getCalculationExpr() const override;

private:

	IExpression *_lhs;
    IExpression *_rhs;
	
	char _op;
};

#endif