#include "Sub_Node.h"

Sub_Node :: Sub_Node(void)
        :Binary_Expr_Node() { }

Sub_Node :: ~Sub_Node(void) { }

int Sub_Node :: evaluate (int n1, int n2) const
{
    return (n1 - n2);
} //end evaluate

virtual void Sub_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Sub_Node(*this);
} //end accept