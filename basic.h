#ifndef basic_h
#define basic_h

#include <unordered_map>
#include <string>
#include <vector>
#include <stack>

#include "program.h"

class Basic {
public:

	Basic();
	void newProgram();	
	static Basic *instance();

	virtual void add(IProgram* program);

	void create(std::string varname);
	void assign(std::string varname, double val);

	bool exists(std::string varname) const;
	bool inited(std::string varname) const;
	double getVariableValue(std::string varname) const;

	std::size_t getExecutingLine() const;
	
	IProgram* getProgramOnLine(std::size_t line) const; 
	std::size_t getProgramsSize() const;
	void goToProgramOnLine(std::size_t line);
	

	void pushIf(std::size_t ifc);
	void addElse(std::size_t elsec);
	
	struct IfCompilation
	{
		std::size_t _if = 0;
		std::size_t _else = 0;	
	};

	IfCompilation topIfElse();
	void popIfElse();
	
	void list() const;
	void load();
	void exec();

private:

	std::unordered_map<std::string, std::pair<bool, double>> _variables;
	std::vector<IProgram*> _programs;
	
	std::stack<IfCompilation> _if;
	std::stack<std::size_t> _for;
	
	bool _freezeExecutingLineCounter = false;
	std::size_t _executingLine = 0;

	static Basic *b;
};

#endif