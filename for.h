#ifndef for_h
#define for_h

#include <string>

#include "double.h"
#include "program.h"
#include "labeled.h"

class For : public IProgram, public Labeled
{
public:

	For(char *varCtrName, double ctrValue, char *varNameEnd);
	virtual void exec() override;
    void setNext(std::size_t next);

	std::vector<std::string> getCCode();
	std::vector<std::string> getIrCode();

private:

	std::string _varCtrName;
	double _ctrValue;
    std::string _varNameEnd;
    std::size_t _next = 0;
};

#endif