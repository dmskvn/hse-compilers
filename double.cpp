#include "expr.h"

Double::Double(const char * name, double d)
:_name(name),
_d(d)
{}

const std::string Double::type() const
{
    return "double";
}

const std::string Double::asString() const
{
    return std::to_string(_d);
}

int Double::asInt() const
{
    return int(_d);
}

double Double::asDouble() const
{
    return _d;
}