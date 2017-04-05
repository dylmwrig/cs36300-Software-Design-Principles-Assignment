#include "Paren_Command.h"

//should have the lowest precedence out of any command, guaranteed
Paren_Command :: Paren_Command(Stack<int> & s)
        :Binary_Expr_Node(s, -1){ }

//just including this to fulfill inheritance rules
//no need to evaluate anything since the parenthesis is just a marker in the expression
int Paren_Command :: evaluate (int n1, int n2) const { } //end evaluate