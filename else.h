#ifndef else_h
#define else_h

#include "program.h"
#include "labeled.h"

#include  <cstddef>

class Else : public IProgram, public Labeled
{
public:

    Else();
    
    virtual void exec() override;
    void setEnd(std::size_t endIfLine);
    void setJumpToEnd(bool jumpToEnd);

    virtual std::vector<std::string> getIrCode() override;
	virtual std::vector<std::string> getCCode() override;

private:

    std::size_t _endIfLine = 0;
    bool _jumpToEnd = false;
};

#endif