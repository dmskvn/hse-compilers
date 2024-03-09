#include "basic.h"
#include "let.h"

#include <iostream>

Let::Let(char *name, double expr)
:_name(name),
_expr(expr)
{}

void Let::exec()
{
    std::cout << "!! EXECING LET " << std::endl;
    Basic::instance()->create(_name);
    Basic::instance()->assign(_name, _expr);
}
