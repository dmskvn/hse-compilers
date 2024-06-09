#include "basic.h"

#include <iostream>
#include <stdexcept>

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream> 

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

Basic::Basic()
{
	_programs.reserve(100);
}

void Basic::add(IProgram* program)
{
	_programs.push_back(program);
	//std::cout << "Basic event: program added. Size: " << _programs.size() << std::endl;
}

void Basic::assign(std::string name, double val)
{
	if (!_variables.count(name))
	{
		throw std::logic_error("Variable" + name + "does not exist");
	}
	_variables[name].second = val;
	_variables[name].first = true;
	
	//std::cout << "Basic event: variable " << name << " assigned " << val << std::endl;
}

void Basic::create(std::string name)
{
	if (_variables.count(name))
	{
		throw std::logic_error("Variable" + name + "already exists");
	}
	_variables[name] = std::make_pair(false, 0);
	//std::cout << "Basic event: variable " << name << " created " << std::endl;
}

void Basic::newProgram()
{
    std::cout << "Start new program" << std::endl;
}

void Basic::list() const
{
	std::cout << "Files: " << std::endl;
    for (const auto & entry : std::filesystem::directory_iterator("."))
	{
        std::cout << entry.path() << std::endl;
	}
}

bool Basic::exists(std::string varname) const
{
	return _variables.count(varname);
}

bool Basic::inited(std::string varname) const
{
	return _variables.at(varname).first;
}

double Basic::getVariableValue(std::string varname) const
{
	if (!_variables.at(varname).first)
	{
		throw std::logic_error("Variable" + varname + "not initilized");
	}
	return _variables.at(varname).second;
}

std::size_t Basic::getExecutingLine() const
{
	return _executingLine; 
}

IProgram* Basic::getProgramOnLine(std::size_t line) const
{
	return _programs[line];
}

std::string Basic::getNextLabelCounter()
{
	_labelCounter[0] = _labelCounter[0] + 1;
	//std::cout << "---- Label counter " << _labelCounter << std::endl;
	return _labelCounter;
}

std::size_t Basic::getProgramsSize() const
{
	return _programs.size();
}

void Basic::goToProgramOnLine(std::size_t goToline)
{
	//std::cout << "Basic event: Go to executing line " << goToline << std::endl;
	_freezeExecutingLineCounter = true;
	_executingLine = goToline;
}

void Basic::pushIf(std::size_t ifc)
{
	//std::cout << "Basic event: If pushed on line " << ifc << std::endl;
	_if.push({ifc, 0});
}

void Basic::addElse(std::size_t elsec)
{
	//std::cout << "Basic event: Else added on line " << elsec << std::endl;
	_if.top()._else = elsec;
}

Basic::IfCompilation Basic::topIfElse()
{
	return _if.top();
}

void Basic::popIfElse()
{
	//std::cout << "Basic event: If " << _if.top()._if << " else " << _if.top()._else \
	//<< "poped" << std::endl;
	_if.pop();
}

void Basic::load()
{
	std::cout << "Program to load: " << std::endl;
	std::cin >> _fileName;

	yyin = fopen(_fileName.c_str(), "r");

	if(!yyin){
		std::cout << "ERROR: could not read file: " << _fileName << std::endl;
		yyin = stdin;
	}
	else
	{
		std::cout << "FILE " << _fileName << " LOADED. EXECUTING ..." << std::endl; 
	}
}

void Basic::exec()
{
	//std::cout << "---- EXECING " << _programs.size() << std::endl;

	for(;_executingLine < _programs.size();)
	{
		//std::cout << "---- EXEC " << _executingLine << " " << _programs[_executingLine] << std::endl;
		_programs[_executingLine]->exec();
		if (_freezeExecutingLineCounter)
		{
			_freezeExecutingLineCounter = false;
		}
		else
		{
			++_executingLine;
		}
	}

	std::ofstream ir_code;
  	ir_code.open (_fileName + ".ir",  std::ofstream::out);

	for(std::size_t i = 0; i < _programs.size(); ++i)
	{
		//std::cout << "---- IR " << i << std::endl;
		auto irs = _programs[i]->getIrCode();
		//std::cout << "---- is size " << irs.size() << std::endl;
		for (const auto& ir : irs)
		{
			ir_code << ir << '\n';
		}
	}
	ir_code.close();

	
	std::ofstream c_code;
  	c_code.open(_fileName + ".c",  std::ofstream::out);

	c_code << "#include <stdio.h>" << '\n';
	c_code << "int main(){" << '\n';

	for(std::size_t i = 0; i < _programs.size(); ++i)
	{
		//std::cout << "---- IR " << i << std::endl;
		auto codes = _programs[i]->getCCode();
		//std::cout << "---- is size " << irs.size() << std::endl;
		for (const auto& code : codes)
		{
			c_code << code << '\n';
		}
	}

	c_code << "}";
	c_code.close();
}

void Basic::pushFor(std::size_t forLine)
{
	_for.push(forLine);
}

std::size_t Basic::topFor() const
{
	return _for.top();
}

void Basic::popFor()
{
	_for.pop();
}

// void Basic::aquireIdleMode()
// {
// 	_idle = true;
// }

// void Basic::releaseIdleMode()
// {
// 	_idle = false;
// }
	