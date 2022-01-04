//declaring an open command for handling parentheses
#ifndef _OPEN_EX_COMMAND_H_
#define _OPEN_EX_COMMAND_H_



// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Expr_Command.h"
#include "Stack.h"

class Open_Ex_Command : public Expr_Command
{

	public:
	Open_Ex_Command(void);
	void execute(Stack<int> & s);
	int get_prec();
	
	private: 
	int prec_;


};

#endif
