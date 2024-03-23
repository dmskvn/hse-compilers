#ifndef let_h
#define let_h

#include "double.h"
#include "program.h"
#include "expression.h"

class Let : public IProgram {
public:

	Let(char *name, double val);
	Let(char *name, IExpression *expr);
	virtual void exec() override;
	virtual ~Let() override;
	
private:
	std::string _name;
	const double _val;
	IExpression *_expr;
};

#endif