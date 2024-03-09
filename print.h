#ifndef print_h
#define print_h

#include "program.h"
#include <string>

class Print : public IProgram {
public:

	Print(char* varname);
	virtual void exec() override;
	
private:
	std::string _varname;
};

#endif