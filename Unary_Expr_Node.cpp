#include "Unary_Expr_Node.h"

int Unary_Expr_Node :: evaluate (void)
{
    if (this->child_)
    {
        return this->child_->evaluate ();
    } //end if
} //end evaluate