#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

//declaring calculator wrapper facade to encapsulate expression evaluation capabilities

#include <string>
#include "Expr_Comm_Factory.h"
#include "Array.h"


class Calculator
{
	public:
	
	Calculator(void);
	~Calculator(void);
	void infix_to_postfix(std::string & infix, Expr_Comm_Factory & factory, Array<Expr_Command *> & postfix);
	int count_and_check(std::string & str);
	bool expr_precheck(std::string & str);
	void run_calculator(void);




};




#endif



