#ifndef else_h
#define else_h

#include "program.h"

#include  <cstddef>

class Else : public IProgram
{
public:

    Else();
    virtual void exec() override;
    void setEnd(std::size_t endIfLine);
    void setJumpToEnd(bool jumpToEnd);

private:

    std::size_t _endIfLine = 0;
    bool _jumpToEnd = false;
};

#endif