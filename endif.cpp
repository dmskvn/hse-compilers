#include "endif.h"

#include "basic.h"

#include "ifthen.h"
#include "else.h"

#include <iostream>

EndIf::EndIf()
{

    const auto programNum = Basic::instance()->getProgramsSize();
    //std::cout << "Endif ctor on line " << programNum << std::endl;

    auto ifElseTokenPosition = Basic::instance()->topIfElse();

    auto *ifThenProgram = static_cast<IfThen*>(
        Basic::instance()->getProgramOnLine(ifElseTokenPosition._if)
    );

    //std::cout << "End if " << ifElseTokenPosition._if << " " << ifThenProgram << std::endl;

    ifThenProgram->setEnd(programNum);

    if(ifElseTokenPosition._else)
    {
        ifThenProgram->setElse(ifElseTokenPosition._else);

        auto* elseProgram = static_cast<Else*>(
            Basic::instance()->getProgramOnLine(ifElseTokenPosition._else)
        );

        elseProgram->setEnd(programNum);
    }

    Basic::instance()->popIfElse();
}

void EndIf::exec()
{}

std::vector<std::string> EndIf::getIrCode()
{
    return {{"LABEL " + this->getLabel() + " :"}};
}

std::vector<std::string> EndIf::getCCode()
{
    return {{"}"}};
}