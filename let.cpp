#include "basic.h"
#include "let.h"

#include <iostream>

Let::Let(char *name)
:_declareOnly(true),
_name(name),
_val(0),
_expr(nullptr)
{
    //std::cout << "Let ctor. Declare only " << " Name " << _name << std::endl;
}


Let::Let(char *name, double val)
:_declareOnly(false),
_name(name),
_val(val),
_expr(nullptr)
{
    //std::cout << "Let ctor. " << this << "Name"  << name << " val " << _val << std::endl;
}

Let::Let(char *name, IExpression *expr)
:_declareOnly(false),
_name(name),
_val(0),
_expr(expr)
{}

void Let::exec()
{
    std::string res ("MOV " + _name + " ");
    if (_expr == nullptr)
    {
        Basic::instance()->create(_name);
        if (!_declareOnly)
        {
            Basic::instance()->assign(_name, _val);
            res +=  _val;
        }
    }
    else
    {
        const auto val =  _expr->value();
        Basic::instance()->assign(_name, _expr->value());
        res += val;
    }
}

std::vector<std::string> Let::getIrCode() 
{
    if (_expr == nullptr)
    {
        return {{"MOV "  + _name + ", " + std::to_string(_val)}};
    }
    else
    {
        return {{"MOV "  + _name + ", " + _expr->getCalculationExpr()}};
    }
}

std::vector<std::string> Let::getCCode()
{
    if (_declareOnly)
    {
        return {{"double " + _name + "=0;" }};
    }

    if (_expr == nullptr)
    {
        return {{"double " + _name + "=" + std::to_string(_val) + ";"}};
    }
    else
    {
        return {{_name + "=" + _expr->getCalculationExpr() + ";"}};
    }
}


Let::~Let()
{
    //std::cout << "LET DTOR" << std::endl;
}
