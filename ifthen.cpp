#include "basic.h"

#include "ifthen.h"

#include <iostream>

IfThen::IfThen(std::size_t line, char *lhs, char *rhs, char *op)
:_lhs(lhs),
_rhs(rhs),
_op(op)
{
    Basic::instance()->pushIf(line);
}

void IfThen::setElse(std::size_t elseLine)
{
    _elseLine = elseLine;
}

void IfThen::setEnd(std::size_t endIfLine)
{
    _endIfLine = endIfLine;
}

void IfThen::exec()
{
}
