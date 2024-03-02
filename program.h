#ifndef program_h
#define program_h

class IProgram
{
    public:
    virtual void exec() const = 0;
    virtual ~IProgram() = default;
};

#endif