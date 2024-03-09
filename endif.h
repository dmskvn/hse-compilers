#ifndef endif_h
#define endif_h

#include "program.h"
#include  <cstddef>

class EndIf : public IProgram
{
public:

    EndIf(std::size_t line);
    virtual void exec() override;
};

#endif