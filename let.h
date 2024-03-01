#include "program.h"

class Let : public IProgram {
public:
	Let(char *name, const Double *expr);
	~Let();	

	void execute() const;
	
private:
	std::string _name;
	const Double *_expr;
};