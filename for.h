#ifndef for_h
#define for_h

#include <string>

#include "double.h"
#include "program.h"

class For : public IProgram {
public:

	For(char *varCtrName, double ctrValue, char *varNameEnd);
	virtual void exec() override;
    void setNext(std::size_t next);
	
private:

	std::string _varCtrName;
	double _ctrValue;
    std::string _varNameEnd;
    std::size_t _next = 0;
};

#endif