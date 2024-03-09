#ifndef program_h
#define program_h

class IProgram
{
    public:
    virtual void exec() = 0;
    virtual ~IProgram() = default;
};

#endif