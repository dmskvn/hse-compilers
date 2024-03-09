#include "endif.h"

#include "basic.h"

#include "ifthen.h"
#include "else.h"

EndIf::EndIf(std::size_t line)
{
    auto ifElseTokenPosition = Basic::instance()->topIfElse();

    auto *ifThenProgram = static_cast<IfThen*>(
        Basic::instance()->getProgram(ifElseTokenPosition._if)
    );

    ifThenProgram->setEnd(line);

    if(ifElseTokenPosition._else)
    {
        auto* elseProgram = static_cast<Else*>(
            Basic::instance()->getProgram(ifElseTokenPosition._else)
        );
        elseProgram->setEnd(line);
    }

    Basic::instance()->popIfElse();

}

void EndIf::exec()
{

}