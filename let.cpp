#include "basic.h"
#include "let.h"

Let::Let(char *name, const Double *expr)
:_name(name),
_expr(expr)
{}

void Let::execute() const
{
    Basic::instance()->crete(name);
    Basic::instance()->assign(name, _expr->value());
}
