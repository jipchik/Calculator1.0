//implmenetation of concrete command factory

#include "Stack_Expr_Comm_Factory.h"


Stack_Expr_Comm_Factory::Stack_Expr_Comm_Factory()
:	add_(new Add_Ex_Command()),
	sub_(new Sub_Ex_Command()),
	div_(new Div_Ex_Command()),
	mult_(new Mult_Ex_Command()),
	mod_(new Mod_Ex_Command()),
	open_(new Open_Ex_Command())
{}

Stack_Expr_Comm_Factory::~Stack_Expr_Comm_Factory(void)
{
	delete add_;
	delete sub_;
	delete div_;
	delete mult_;
	delete mod_;
	delete open_;
}

Num_Ex_Command * Stack_Expr_Comm_Factory::create_num_command(int num)
{
	return new Num_Ex_Command(num);
}

Add_Ex_Command * Stack_Expr_Comm_Factory::create_add_command(void)
{
	return this->add_;
}

Sub_Ex_Command * Stack_Expr_Comm_Factory::create_sub_command(void)
{
	return this->sub_;
}

Mult_Ex_Command * Stack_Expr_Comm_Factory::create_mult_command(void)
{
	return this->mult_;
}

Div_Ex_Command * Stack_Expr_Comm_Factory::create_div_command(void)
{
	return this->div_;
}

Mod_Ex_Command * Stack_Expr_Comm_Factory::create_mod_command(void)
{
	return this->mod_;
}

Open_Ex_Command * Stack_Expr_Comm_Factory::create_open_command(void)
{
	return this->open_;
}
