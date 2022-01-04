//declaration of concrete stack factory 

#ifndef _STACK_EXPR_COMM_FACTORY_H_
#define _STACK_EXPR_COMM_FACTORY_H_

#include "Expr_Comm_Factory.h"
#include "Stack.h"
#include "Num_Ex_Command.h"
#include "Add_Ex_Command.h"
#include "Sub_Ex_Command.h"
#include "Mult_Ex_Command.h"
#include "Div_Ex_Command.h"
#include "Mod_Ex_Command.h"
#include "Open_Ex_Command.h"

class Stack_Expr_Comm_Factory : public Expr_Comm_Factory
{

	public:
	Stack_Expr_Comm_Factory();

	~Stack_Expr_Comm_Factory(void);	
	virtual Num_Ex_Command * create_num_command(int num);
	virtual Add_Ex_Command * create_add_command(void);
	virtual Sub_Ex_Command * create_sub_command(void);
	virtual Mult_Ex_Command * create_mult_command(void);
	virtual Div_Ex_Command * create_div_command(void);
	virtual Mod_Ex_Command * create_mod_command(void);
	virtual Open_Ex_Command * create_open_command(void);

	private:
	
	Add_Ex_Command * add_;
	Sub_Ex_Command * sub_;
	Div_Ex_Command * div_;
	Mult_Ex_Command * mult_;
	Mod_Ex_Command * mod_;
	Open_Ex_Command * open_;
};


#endif
