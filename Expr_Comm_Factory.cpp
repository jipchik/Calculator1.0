//implementing move constructor and assignment operator for moving resources to concrete factories

#include "Expr_Comm_Factory.h"


Expr_Comm_Factory::Expr_Comm_Factory(void){}


Expr_Comm_Factory::Expr_Comm_Factory(const Expr_Comm_Factory & factory)
{}

const Expr_Comm_Factory & Expr_Comm_Factory::operator = (const Expr_Comm_Factory & rhs)
{
	if(this != &rhs)
	{
		return (*this);
	}
	return (*this);
}
