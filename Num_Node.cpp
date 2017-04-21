#include "Num_Node.h"
#include "Expr_Node_Visitor.h"

Num_Node :: Num_Node() { }

Num_Node :: Num_Node (int n)
        :n_ (n){ }

Num_Node :: ~Num_Node () { }

int Num_Node :: evaluate (void)
{
    return n_;
} //end execute

void Num_Node :: setNum (int num)
{
    n_ = num;
} //end setNum

void Num_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Num_Node(*this);
} //end accept