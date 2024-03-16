#include "basic.h"
#include "let.h"

#include <iostream>

Let::Let(char *name, double expr)
:_name(name),
_expr(expr)
{
    std::cout << "Let ctor. " << this << "Name"  << name << " val " << expr << std::endl;
}

void Let::exec()
{
    Basic::instance()->create(_name);
    Basic::instance()->assign(_name, _expr);
}

Let::~Let()
{
    std::cout << "LET DTOR" << std::endl;
}
