#include "for.h"
#include "next.h"

#include "basic.h"

#include <iostream>

For::For(char *varCtrName, double ctrValue, char *varNameEnd)
:_varCtrName(varCtrName),
_ctrValue(ctrValue),
_varNameEnd(varNameEnd)
{
    const auto programNum = Basic::instance()->getProgramsSize();

    //std::cout << "For ctor on line " << _varCtrName << " "
    //<< this << " " <<  _ctrValue <<  " "  << _varNameEnd << std::endl;

    Basic::instance()->pushFor(programNum);
}

void For::exec()
{
    if(!Basic::instance()->exists(_varCtrName))
    {
        Basic::instance()->create(_varCtrName);
        Basic::instance()->assign(_varCtrName, _ctrValue);
    }

    if(_ctrValue >= Basic::instance()->getVariableValue(_varNameEnd))
    {
        auto* forNextProgram = static_cast<Next*>(
            Basic::instance()->getProgramOnLine(_next)
        );
        forNextProgram->setEndLoop(true);
        Basic::instance()->goToProgramOnLine(_next);
    }
    else
    {
        ++_ctrValue;
        Basic::instance()->assign(_varCtrName, _ctrValue);
    }
}

void For::setNext(std::size_t next)
{
    _next = next;
}

std::vector<std::string> For::getCCode()
{
    std::vector<std::string> res;

    res.push_back("double " + _varCtrName + " = " + std::to_string(0) + ";");
    res.push_back("while(" + _varCtrName + "!=" + _varNameEnd + ")");
    res.push_back("{");
    res.push_back("++" + _varCtrName + ";");
    return res;

}

std::vector<std::string> For::getIrCode()
{
    std::vector<std::string> res;

    auto* forNextProgram = static_cast<Next*>(
            Basic::instance()->getProgramOnLine(_next)
    );

    res.push_back("MOV " + _varCtrName + "," + std::to_string(_ctrValue));
    res.push_back("CMP <> " + _varCtrName + "," + _varNameEnd + ":" + forNextProgram->getLabel() + "," + "NEXT_INSTRUCTION");
    return res;
}