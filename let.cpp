#include "basic.h"
#include "let.h"

#include <iostream>

Let::Let(char *name, double val)
:_name(name),
_val(val),
_expr(nullptr)
{
    std::cout << "Let ctor. " << this << "Name"  << name << " val " << _val << std::endl;
}

Let::Let(char *name, IExpression *expr)
:_name(name),
_val(0),
_expr(expr)
{}

void Let::exec()
{
    if (_expr == nullptr)
    {
        Basic::instance()->create(_name);
        Basic::instance()->assign(_name, _val);
    }
    else
    {
        Basic::instance()->assign(_name, _expr->value());
    }
}

Let::~Let()
{
    //std::cout << "LET DTOR" << std::endl;
}
