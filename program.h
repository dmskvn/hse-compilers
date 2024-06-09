#ifndef program_h
#define program_h

#include <string>
#include <vector>

class IProgram
{
    public:

    virtual void exec() = 0;
    virtual ~IProgram() = default;

    virtual std::vector<std::string> getIrCode() {return {{}};}
	virtual std::vector<std::string> getCCode() {return {{}};}
};

#endif