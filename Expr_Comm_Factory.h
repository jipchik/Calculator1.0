//declaration of the expression factory 



// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _EXPR_COMM_FACTORY_H_
#define _EXPR_COMM_FACTORY_H_

#include "Num_Ex_Command.h"
#include "Add_Ex_Command.h"
#include "Sub_Ex_Command.h"
#include "Mult_Ex_Command.h"
#include "Div_Ex_Command.h"
#include "Mod_Ex_Command.h"
#include "Open_Ex_Command.h"


class Expr_Comm_Factory
{
	public: 
	virtual Num_Ex_Command * create_num_command(int num) = 0;
	virtual Add_Ex_Command * create_add_command(void) = 0;
	virtual Sub_Ex_Command * create_sub_command(void) = 0;
	virtual Mult_Ex_Command * create_mult_command(void) = 0;
	virtual Div_Ex_Command * create_div_command(void) = 0;
	virtual Mod_Ex_Command * create_mod_command(void) = 0;
	virtual Open_Ex_Command * create_open_command(void) = 0;

};



#endif
