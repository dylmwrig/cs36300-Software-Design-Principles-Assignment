#include "Open_Paren_Node.h"

//should have the lowest precedence out of any command, guaranteed
Open_Paren_Node :: Open_Paren_Node()
        :Binary_Expr_Node(){ }

//just including this to fulfillParen_Command inheritance rules
//no need to evaluate anything since the parenthesis is just a marker in the expression
int Open_Paren_Node :: evaluate (int n1, int n2) const { } //end evaluate