#include "operatorexpression.h"
#include <iostream>

OperatorExpression::OperatorExpression(IExpression *lhs, IExpression *rhs, char op)
:_lhs(lhs),
_rhs(rhs),
_op(op)
{
	std::cout << "OperatorExpression ctor op " << op << std::endl;
}

double OperatorExpression::value() const {
	
	if (_op == '+') return _lhs->value()+_rhs->value();
	if (_op == '-') return _lhs->value()-_rhs->value();
	if (_op == '*') return _lhs->value()*_rhs->value();
	if (_op == '/') return _lhs->value()/_rhs->value();
	return 0;
}