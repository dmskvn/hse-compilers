#include "basic.h"

#include <iostream>
#include <stdexcept>

Basic *Basic::b;

Basic *Basic::instance(){
	if( b == NULL )
		b = new Basic();
	return b;
}

void Basic::assign(std::string name, double val)
{
	if (!_variables.count(name))
	{
		throw std::logic_error("Variable" + name + "does not exist");
	}
	_variables[name].second = val;
}

void Basic::create(std::string name)
{
	if (_variables.count(name))
	{
		throw std::logic_error("Variable" + name + "already exists");
	}
	_variables[name] = std::make_pair(true, 0);
}

void Basic::newProgram(){
    std::cout << "Start new program" << std::endl;
}
