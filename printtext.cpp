#include "printtext.h"
#include <iostream>

#include "basic.h"

PrintText::PrintText(char* text)
:_text(text)
{}

void PrintText::exec()
{
    std::cout << _text << std::endl;
}
