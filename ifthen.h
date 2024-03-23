#ifndef ifthen_h
#define ifthen_h

#include "program.h"

#include <string>

class IfThen : public IProgram 
{
public:

	IfThen(char *lhs, char *op, char *rhs);

    void setElse(std::size_t elseLine);

	void setEnd(std::size_t endIfLine);

    virtual void exec() override;

private:

    const std::string _lhs;
    const std::string _rhs;
    const std::string _op; 

    std::size_t _elseLine = 0;
    std::size_t _endIfLine = 0;
};

#endif