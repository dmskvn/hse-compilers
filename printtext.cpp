#include "printtext.h"
#include <iostream>

#include "basic.h"

PrintText::PrintText(char* text)
:_text(text)
{
    _text.erase(_text.begin());
    _text.erase(_text.end()-1); 
}

void PrintText::exec()
{
    std::cout << _text << std::endl;
}

std::vector<std::string> PrintText::getIrCode()
{
    return {{"PRINT, " + _text}};
}

std::vector<std::string> PrintText::getCCode()
{
    return {{"printf(\"" + _text + "\");"}};
}
