#include "Num_Node.h"

Num_Node :: Num_Node (int n)
        :n_ (n){ }

int Num_Node :: evaluate (void)
{
    return n_;
} //end execute

virtual void Num_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Num_Node(*this);
} //end accept