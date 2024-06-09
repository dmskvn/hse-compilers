#ifndef endif_h
#define endif_h

#include "program.h"
#include "labeled.h"
#include  <cstddef>

class EndIf : public IProgram, public Labeled
{  
public:

    EndIf();
    virtual void exec() override;
    virtual std::vector<std::string> getIrCode() override;
	virtual std::vector<std::string> getCCode() override;

};

#endif