//modulus command declaration


#ifndef _MOD_EX_COMMAND_H_
#define _MOD_EX_COMMAND_H_


// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Expr_Command.h"
#include "Stack.h"

class Mod_Ex_Command : public Expr_Command
{
	public:
	Mod_Ex_Command(void);
	virtual void execute(Stack<int> & s);
	int get_prec();

	private:
	int prec_;
};

#endif
