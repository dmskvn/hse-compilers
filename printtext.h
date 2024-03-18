#ifndef printtext_h
#define printtext_h

#include "program.h"
#include <string>

class PrintText : public IProgram {
public:

	PrintText(char* text);
	virtual void exec() override;
	
private:
	std::string _text;
};

#endif