#include "basic.h"

#include <iostream>
#include <stdexcept>

#include <string>
#include <iostream>
#include <filesystem>

#include <unistd.h>
#include <sys/dir.h>

#include "basic.h"

extern "C" FILE *yyin;

Basic *Basic::b;

Basic *Basic::instance(){
	if( b == NULL )
		b = new Basic();
	return b;
}

void Basic::add(IProgram* program)
{
	_programs.push_back(program);
	std::cout << "Basic event: program added. Size: " << _programs.size() << std::endl;
}

void Basic::assign(std::string name, double val)
{
	if (!_variables.count(name))
	{
		throw std::logic_error("Variable" + name + "does not exist");
	}
	_variables[name].second = val;
	_variables[name].first = true;
	
	std::cout << "Basic event: variable " << name << " assigned " << val << std::endl;
}

void Basic::create(std::string name)
{
	if (_variables.count(name))
	{
		throw std::logic_error("Variable" + name + "already exists");
	}
	_variables[name] = std::make_pair(false, 0);
	std::cout << "Basic event: variable " << name << " created " << std::endl;
}

void Basic::newProgram()
{
    std::cout << "Start new program" << std::endl;
}

void Basic::list() const
{
	std::cout << "+++++ LIST +++++" << std::endl;

	std::cout << "Files: " << std::endl;
    for (const auto & entry : std::filesystem::directory_iterator("."))
	{
        std::cout << entry.path() << std::endl;
	}

	std::cout << "+++++ LIST +++++" << std::endl;
}

bool Basic::exists(std::string varname) const
{
	return _variables.count(varname);
}

bool Basic::inited(std::string varname) const
{
	return _variables.at(varname).first;
}

double Basic::value(std::string varname) const
{
	return _variables.at(varname).second;
}

std::size_t Basic::getExecutingLine() const
{
	return _executingLine; 
}

void Basic::setExecutingLine(std::size_t executingLine)
{
	_executingLine = executingLine;
}

IProgram* Basic::getProgram(std::size_t line) const
{
	return _programs[_executingLine];
}

void Basic::pushIf(std::size_t ifc)
{
	_if.push({ifc, 0});
}

void Basic::addElse(std::size_t elsec)
{
	_if.top()._else = elsec;
}

Basic::IfCompilation Basic::topIfElse()
{
	return _if.top();
}

void Basic::popIfElse()
{
	_if.pop();
}

void Basic::load()
{
	std::cout << "Program to load: " << std::endl;
	std::string fileName;
	std::cin >> fileName;

	yyin = fopen(fileName.c_str(), "r");

	if(!yyin){
		std::cout << "ERROR: could not read file: " << fileName << std::endl;
		yyin = stdin;
	}
	else
	{
		std::cout << "FILE " << fileName << " LOADED. EXECUTING ..." << std::endl; 
	}
}

void Basic::exec()
{
	std::cout << "---- EXECING " << std::endl;

	for(;_executingLine < _programs.size(); ++_executingLine)
	{
		_programs[_executingLine]->exec();
	}
}

// void Basic::aquireIdleMode()
// {
// 	_idle = true;
// }

// void Basic::releaseIdleMode()
// {
// 	_idle = false;
// }
	