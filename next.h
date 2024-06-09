#ifndef next_h
#define next_h

#include "program.h"
#include "labeled.h"
#include <cstdio>

class Next : public IProgram, public Labeled {
public:

	Next();
	virtual void exec() override;
    void setEndLoop(bool endLoop);
    virtual std::vector<std::string> getIrCode() override;
    virtual std::vector<std::string> getCCode() override;
	
private:

    bool _endLoop = false;
    std::size_t _forLine = 0;
};

#endif