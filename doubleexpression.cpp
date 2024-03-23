#include "doubleexpression.h"

#include "basic.h"

#include <iostream>

DoubleExpression::DoubleExpression(double d)
:_d(d),
_varName("")
{
    //std::cout << "DoubleExpression ctor " << d << std::endl;
}

DoubleExpression::DoubleExpression(char *varName)
:_d(0),
_varName(varName)
{
    //std::cout << "DoubleExpression ctor " << _varName << std::endl;
}

double DoubleExpression::value() const
{
    if (!_varName.empty())
    {
        return Basic::instance()->getVariableValue(_varName);
    }
    else
    {
        return _d;
    }
    return 0;
}