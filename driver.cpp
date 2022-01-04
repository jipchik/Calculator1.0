//driver for expression evaluator

#include "Calculator.h"


// COMMENT: Instead of using C functions to implement parts of the
// calculator. It would be better suited to use a Wrapper Facade.
//
// RESPONSE:: Added wrapper facade "Calculator" to implement the expression evaluation capabilities


//all functionality of the calculator is encapsulated in the Calculator wrapper facade, making the client code squeaky clean
int main(void)
{
	//instantiate a calculator object
	Calculator c;
	
	//run that boi
	c.run_calculator();

}



