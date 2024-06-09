#include "else.h"
#include "ifthen.h"
#include "endif.h"
#include "basic.h"

#include <iostream>

Else::Else()
{

    const auto programNum = Basic::instance()->getProgramsSize();
    //std::cout << "Else ctor on line " << programNum << std::endl;
    Basic::instance()->addElse(programNum);

    // auto ifElseTokenPosition = Basic::instance()->topIfElse();
    // auto *ifThenProgram = static_cast<IfThen*>(
    //     Basic::instance()->getProgram(ifElseTokenPosition._if)
    // );
    // ifThenProgram->setElse(programNum);
}

void Else::setEnd(std::size_t endIfLine)
{
    _endIfLine = endIfLine;
}

void Else::setJumpToEnd(bool jumpToEnd)
{
    _jumpToEnd = jumpToEnd;
}

void Else::exec()
{
    //std::cout << "Jump to endline " << _jumpToEnd << " .Line " << _endIfLine << std::endl;

    if (_jumpToEnd)
    {
        Basic::instance()->goToProgramOnLine(_endIfLine);
    }
}

std::vector<std::string> Else::getIrCode()
{
    auto endifProgram = static_cast<EndIf*>(Basic::instance()->getProgramOnLine(_endIfLine));
    auto endifLabel = endifProgram->getLabel();
    std::vector<std::string> result;

    result.push_back({"GOTO: " + endifLabel});
    result.push_back({"LABEL " + this->getLabel() + " :"});

    return result;
}

std::vector<std::string> Else::getCCode()
{
    std::vector<std::string> result;
    result.push_back("}");
    result.push_back("else");
    result.push_back("{");
    return result;
}