#ifndef let_h
#define let_h

#include "double.h"
#include "program.h"
#include "expression.h"

class Let : public IProgram {
public:

	Let(char *name);
	Let(char *name, double val);
	Let(char *name, IExpression *expr);

	void exec() override;

	virtual std::vector<std::string> getIrCode() override;
	virtual std::vector<std::string> getCCode() override;

	virtual ~Let() override;

	
private:

	bool _declareOnly;
	std::string _name;
	const double _val;
	IExpression *_expr;
};

#endif