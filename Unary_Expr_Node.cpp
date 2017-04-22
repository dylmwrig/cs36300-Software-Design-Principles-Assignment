#include "Unary_Expr_Node.h"

Unary_Expr_Node :: Unary_Expr_Node() { }

Unary_Expr_Node ::~Unary_Expr_Node() { }

int Unary_Expr_Node :: evaluate (void) const
{
    if (this->child_)
    {
        return this->child_->evaluate ();
    } //end if
} //end evaluate