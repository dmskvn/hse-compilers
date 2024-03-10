#ifndef let_h
#define let_h

#include "double.h"
#include "program.h"

class Let : public IProgram {
public:

	Let(char *name, double expr);
	virtual void exec() override;
	virtual ~Let() override;
	
private:
	std::string _name;
	const double _expr;
};

#endif