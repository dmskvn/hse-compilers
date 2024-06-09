#include "next.h"
#include "for.h"

#include "basic.h"

#include <iostream>

Next::Next()
{
    const auto programNum = Basic::instance()->getProgramsSize();
    //std::cout << "Next ctor on line " << programNum << std::endl;

    _forLine = Basic::instance()->topFor();

    auto *forProgram = static_cast<For*>(
        Basic::instance()->getProgramOnLine(_forLine)
    );

    forProgram->setNext(programNum);

    Basic::instance()->popFor();
}

void Next::exec()
{
    if (_endLoop)
    {
        //std::cout << "next: loop ended" << std::endl;
        _endLoop=false;
    }
    else
    {
        //std::cout << "next: loop not ended" << std::endl;
        Basic::instance()->goToProgramOnLine(_forLine);
    }
}

void Next::setEndLoop(bool endLoop)
{
    _endLoop = endLoop;
}

std::vector<std::string> Next::getIrCode()
{
    auto *forProgram = static_cast<For*>(
        Basic::instance()->getProgramOnLine(_forLine)
    );

    std::vector<std::string> res;
    res.push_back("GOTO " + forProgram->getLabel());
    res.push_back("LABEL " + this->getLabel() + " :");  
    return res;
}

std::vector<std::string> Next::getCCode()
{
    std::vector<std::string> res;
    res.push_back("}");
    return res;
}
