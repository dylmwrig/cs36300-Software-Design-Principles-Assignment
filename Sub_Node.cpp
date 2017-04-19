#include "Sub_Node.h"

Sub_Node :: Sub_Node(void)
        :Binary_Expr_Node() { }

Sub_Node :: ~Sub_Node(void) { }

int Sub_Node :: evaluate (Num_Node * n1, Num_Node * n2) const
{
    return (n1->evaluate() - n2->evaluate());
} //end evaluate

virtual void Sub_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Sub_Node(*this);
} //end accept