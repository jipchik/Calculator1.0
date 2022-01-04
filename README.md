# Calculator1.0

## This project is the first version of a basic mathematical expression evaluator that handles: addition, subtraction, division, multiplication, modulus, and of course parentheses.

- The expression is build by first converting from infix to postfix from what the user inputs to the system.
- From the postfix expression, it then creates commands(using command pattern and flyweight factory pattern), which are then stored in an array(built by yours truly),
which is then iterated over( using iterator pattern) to evaluate the expression and obtain the result. 
