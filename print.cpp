#include "print.h"
#include <iostream>

#include "basic.h"

Print::Print(char* varname)
:_varname(varname)
{}

void Print::exec()
{
    std::cout << "------- PRINT: VAR: " << _varname << "-------" << std::endl;
    const auto exists = Basic::instance()->exists(_varname);
    std::cout << "EXISTS: " <<  exists << std::endl;
    if (exists)
    {
        std::cout << "INITED: " <<  Basic::instance()->inited(_varname) << std::endl;
        std::cout << "VALUE: " <<  Basic::instance()->value(_varname) << std::endl;    
    }
    std::cout << "--------------------------------------------" << std::endl;
}
