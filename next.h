#ifndef next_h
#define next_h

#include "program.h"
#include <cstdio>

class Next : public IProgram {
public:

	Next();
	virtual void exec() override;
    void setEndLoop(bool endLoop);
	
private:

    bool _endLoop = false;
    std::size_t _forLine = 0;
};

#endif