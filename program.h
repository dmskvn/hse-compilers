#pragma once

class IProgram
{
    virtual void exec() const = 0;
    virtual ~IProgram() = default;
};