#ifndef ifthen_h
#define ifthen_h

#include "program.h"

class IfThen : public IProgram 
{
public:

	IfThen(std::size_t line, char *lhs, char *rhs, char *op);

    void setElse(std::size_t elseLine);

	void setEnd(std::size_t endIfLine);

    virtual void exec() override;

private:

    char *_lhs;
    char *_rhs;
    char *_op; 

    std::size_t _elseLine = 0;
    std::size_t _endIfLine = 0;
};

#endif