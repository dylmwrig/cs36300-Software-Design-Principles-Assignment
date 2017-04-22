#include "Sub_Node.h"
#include "Expr_Node_Visitor.h"

Sub_Node :: Sub_Node(void)
        :Binary_Expr_Node() { }

Sub_Node :: Sub_Node(Expr_Node * left, Expr_Node * right)
        :Binary_Expr_Node(left, right) { }

Sub_Node :: ~Sub_Node(void) { }

int Sub_Node :: evaluate () const
{
    return (left_->evaluate() - right_->evaluate());
} //end evaluate

void Sub_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Sub_Node(*this);
} //end accept