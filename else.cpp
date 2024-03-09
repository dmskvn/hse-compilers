#include "else.h"

#include "basic.h"

#include "ifthen.h"

Else::Else(std::size_t line)
{

    auto ifElseTokenPosition = Basic::instance()->topIfElse();

    auto *ifThenProgram = static_cast<IfThen*>(
        Basic::instance()->getProgram(ifElseTokenPosition._if)
    );

    ifThenProgram->setElse(line);
}

void Else::setEnd(std::size_t endIfLine)
{
    _endIfLine = endIfLine;
}

void Else::exec()
{

}