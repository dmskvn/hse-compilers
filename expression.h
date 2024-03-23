#ifndef expr_h
#define expr_h

class IExpression
{
public:
	virtual double value() const = 0;
};

#endif