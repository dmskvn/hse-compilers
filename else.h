#ifndef else_h
#define else_h

#include "program.h"

#include  <cstddef>

class Else : public IProgram
{
public:

    Else(std::size_t line);
    virtual void exec() override;
    void setEnd(std::size_t endIfLine);

private:

    std::size_t _endIfLine = 0;
};

#endif