#include "parenexpression.h"
#include <iostream>

ParenExpression::ParenExpression(IExpression *expr)
:_expr(expr)
{
	//std::cout << "ParenExpression ctor " << std::endl;
}

double ParenExpression::value() const{
	return _expr->value();
}