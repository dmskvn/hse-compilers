#pragma once

#include <unordered_map>
#include <string>

class Basic {
public:
	void newProgram();	
	static Basic *instance();

	void create(std::string name);
	void assign(std::string name, double val);
	
	
private:

	std::unordered_map<std::string, std::pair<bool, double>> _variables;

	static Basic *b;
};
