#include "basic.h"

#include "ifthen.h"
#include "else.h"

#include <iostream>

IfThen::IfThen(char *lhs, char *op, char *rhs)
:_lhs(lhs),
_rhs(rhs),
_op(op)
{
    const auto programNum = Basic::instance()->getProgramsSize();

    std::cout << "If ctor on line " << programNum << " "
    << this << " " <<  _lhs <<  " "  << _op << " "<< _rhs << std::endl;

    Basic::instance()->pushIf(programNum);
}

void IfThen::setElse(std::size_t elseLine)
{
    std::cout << "Set else on" << elseLine << " " << std::endl;
    _elseLine = elseLine;
}

void IfThen::setEnd(std::size_t endIfLine)
{
    std::cout << "Set endline on" << endIfLine << " " << std::endl;
    _endIfLine = endIfLine;
}

void IfThen::exec()
{
    const auto lval = Basic::instance()->getVariableValue(_lhs);
    const auto rval = Basic::instance()->getVariableValue(_rhs);
    auto result = false;

    if (_op == "=")
		result = lval == rval;
	else if(_op == "<")
		result = lval < rval;
	else if(_op == ">")
		result = lval > rval;
	else if(_op == "<=")
		result = lval <= rval;
	else if(_op == "=>")
		result = lval >= rval;
	else if(_op == "<>")
		result = lval != rval;
	
    std::cout << "Condition result " << result << std::endl;

    auto *elseLine = static_cast<Else*>(Basic::instance()->getProgramOnLine(_elseLine));

	if(!result)
    {
        if (_elseLine)
        {
            elseLine->setJumpToEnd(false);
            Basic::instance()->goToProgramOnLine(_elseLine);
        }
    }
    else
    {
        if (_elseLine)
        {
            elseLine->setJumpToEnd(true);
        }
        else
        {
            Basic::instance()->goToProgramOnLine(_endIfLine);
        }
    }
}
