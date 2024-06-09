#ifndef labeled_h
#define labeled_h

#include <string>

class Labeled
{
    std::string _label;

    public:
    Labeled();

    std::string getLabel() const;
};

#endif