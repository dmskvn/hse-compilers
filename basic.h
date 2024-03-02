#ifndef basic_h
#define basic_h

#include <unordered_map>
#include <string>
#include <vector>

#include "program.h"

class Basic {
public:

	void newProgram();	
	static Basic *instance();

	virtual void add(IProgram* program);

	void create(std::string varname);
	void assign(std::string varname, double val);

	bool exists(std::string varname) const;
	bool inited(std::string varname) const;
	double value(std::string varname) const;
	
	
	void list() const;
	void load();
	void exec();
	
private:

	std::unordered_map<std::string, std::pair<bool, double>> _variables;
	std::vector<IProgram*> _programs;

	static Basic *b;
};

#endif