#include "Close_Paren_Node.h"

Close_Paren_Node :: Close_Paren_Node() { }

Close_Paren_Node :: ~Close_Paren_Node() { }

//just including this to fulfillParen_Command inheritance rules
//no need to evaluate anything since the parenthesis is just a marker in the expression
int Close_Paren_Node :: evaluate () const { } //end evaluate

void Close_Paren_Node :: accept(Expr_Node_Visitor &v)
{
    //TODO accept parent
} //end accept