#include "basic.h"

#include <iostream>

Basic *Basic::b;

Basic *Basic::instance(){
	if( b == NULL )
		b = new Basic();
	return b;
}

void Basic::newProgram(){
    std::cout << "Start new program" << std::endl;
}
