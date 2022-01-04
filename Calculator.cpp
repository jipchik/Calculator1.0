//implementing calculator wrapper facade


#include <string>
#include <sstream>
#include <iostream>
#include "Calculator.h"
#include "Array.h"
#include "Array_Iterator.h"
#include "Stack.h"
#include "Stack_Expr_Comm_Factory.h"


Calculator::Calculator(void){}

Calculator::~Calculator(void){}

void Calculator::infix_to_postfix(std::string & infix, Expr_Comm_Factory & factory, Array<Expr_Command *> & postfix)
{
	std::istringstream input(infix);
	std::string token;
	Expr_Command * comm = 0;
	Stack<Expr_Command *> expr;
	int index = 0;

	//handles all operators and operands, properly adds them to the postfix array for execution
	//uses temporary expression command stack to assist in the infix to postfix conversion, as directed by provided pseudocode
	while(!input.eof())
	{
		input >> token;
		//for all operators, create a command of that type, if the stack is empty push it onto the stack
		//if the stack is not empty and the precendence of the newly created command is less than or equal to the top
		//then add the top element to the postfix array, pop the stack, increment index to properly manage the postfix arrays order
		if(token == "+")
		{
			comm = factory.create_add_command();
			while(!expr.is_empty() && comm->get_prec() <= expr.top()->get_prec())
			{
				postfix[index] = expr.top();
				expr.pop();				
				index++;
			}
			expr.push(comm);
		}
		else if(token == "-")
		{
			comm = factory.create_sub_command();
			while(!expr.is_empty() && comm->get_prec() <= expr.top()->get_prec())
			{
				postfix[index] = expr.top();
				expr.pop();
				index++;
			}
			expr.push(comm);
		}
		else if(token == "/")
		{
			comm = factory.create_div_command();
			while(!expr.is_empty() && comm->get_prec() <= expr.top()->get_prec())
			{
				postfix[index] = expr.top();
				expr.pop();
				index++;
			}
			expr.push(comm);
		}
		else if(token == "*")
		{
			comm = factory.create_mult_command();		
			while(!expr.is_empty() && comm->get_prec() <= expr.top()->get_prec())
			{	
				postfix[index] = expr.top();
				expr.pop();
				index++;
			}
			expr.push(comm);
		}
		else if(token == "%")
		{	
			comm = factory.create_mod_command();
			while(!expr.is_empty() && comm->get_prec() <= expr.top()->get_prec())
			{
				postfix[index] = expr.top();
				expr.pop();
				index++;
			}		
			expr.push(comm);
		}
		//for handling parentheses, if it is an opening paren, create an open command and push it onto the stack
		else if(token == "(")
		{
			comm = factory.create_open_command();
			expr.push(comm);		
		}
		//when a closing parentheses is encountered, pop the stack until the open command is found(represented by a precedence of -1)
		//while it is not found add the top element to the postfix array, pop the stack, increment the index, then finally pop the open command
		//off the stack 
		else if (token == ")")
		{
			while(expr.top()->get_prec() != -1)
			{
				postfix[index] = expr.top();
				expr.pop();
				index++;
			}	
			expr.pop();
		}
		else if(token == " ")
		{
			continue;
		}
		//for operands, turn the token into an integer, create a number command, then add it to the postfix array
		//and increment the index to properly manage the order of the postfix array
		else
		{
			int num = stoi(token);
			comm = factory.create_num_command(num);
			postfix[index] = comm;	
			index++;		
		}
	}
		//handles the cases where the last token is received and handled, but there are still operators on the stack
		//while the stack isnt empty add the top element to the postfix array, increment the index, the pop the stack
		while(!expr.is_empty())
		{
			postfix[index] = expr.top();
			index++;
			expr.pop();		
		}
}


int Calculator::count_and_check(std::string & str)
{
	//used to search for zeros, /, and % for validating expressions
	size_t found_div = str.find("/");
	size_t found_zero = str.find("0");
	size_t found_mod = str.find("%");
	//if the difference between a zero and a modulus/division operator is two that indicates 
	//the user is trying to divide or mod something by zero which is not allowed
	//returns a -1 to indicate this
	if(found_zero - found_div == 2 || found_zero - found_mod == 2)
	{
		return -1;
	}
	//counts the number of operators/operands in the provided expression and returns the number
	//this is used for determining the size of the postfix array allocation
	int count = 0;
	std::stringstream input(str);
	std::string token;
	while(!input.eof())
	{
		input >> token;
		if(token != " " && token != ")" && token != "(")
		{
			count++;
		}
	}
	return count;
}

//prechecks the provided expression before it is passed into count_and_check to check for proper operator to operand ratio
bool Calculator::expr_precheck(std::string & str)
{
	int operator_count = 0;
	int num_count = 0;
	
	//loop through string tokens and increment operator_count or num_count depending on what is encountered
	//return true if correct ratio is present, false if not
	std::stringstream input(str);
	std::string token;
	while(!input.eof())
	{
		input >> token;
		if(token == "/" || token == "+" || token == "-" || token == "*" || token == "%")
		{
			operator_count++;
		}
		else if(token == " " || token == ")" || token == "(")
		{
			continue;
		}
		else
		{
			num_count++;
		}
	}	
	
	if(operator_count >= num_count)
	{
		return false;
	}
	else
	{
		return true;
	}

}

void Calculator::run_calculator(void)
{
	//sentry variable to control when to exit the program
	bool keep_going = true;

	while(keep_going)
	{	
		//take user input	
		std::string infix;
		std::cout << "Enter your expression: " << std::endl;
		getline(std::cin, infix);
		//count and check the users provided expression
		//precheck the expression to confirm it has correct ratio of operators to operands
		bool is_valid = expr_precheck(infix);
		int num_commands = this->count_and_check(infix);
		//exit while loop if the user types QUIT in all caps
		if(is_valid)
		{
			if(infix == "QUIT")
			{
				keep_going = false;
			}
			//if the user enters an invalid expression, print the statement and prompt for another user input
			else if(num_commands == -1)
			{
				std::cout << std::endl;
				std::cout << "Invalid Expression: Cannot divide or mod by 0." << std::endl;
				std::cout << std::endl;
			}
			//if it is a valid expression, convert to postfix format, use iterator to iterate over the commands and execute them
			//print the result of the expression
			else if(num_commands > 1)
			{
				Stack<int> result;
				Stack_Expr_Comm_Factory factory;

				Array<Expr_Command *> postfix(num_commands);

				this->infix_to_postfix(infix, factory, postfix);

				typedef Array_Iterator<Expr_Command *> Expr_Iter;
				Expr_Iter iter(postfix);
				//when iterating over elements, if the command object is a number its memory needs cleaned up
				//check if the object is a number(indicated by a precedence of 0) and delete it
				for(; !iter.is_done(); iter.advance())
				{
					(*iter)->execute(result);
					if((*iter)->get_prec() == 0)
					{
						delete (*iter);
					}
				}
				int res = result.top();
				std::cout << res << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			std::cout << "Invalid Expression: Cannot have more or equal number of operators as operands in an expression." << std::endl;
			std::cout << std::endl;
		}
	}
}

