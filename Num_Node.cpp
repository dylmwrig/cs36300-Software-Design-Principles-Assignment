#include "Num_Node.h"
#include "Expr_Node_Visitor.h"

Num_Node :: Num_Node() { }

Num_Node :: Num_Node (int n)
        :n_ (n){ }

Num_Node :: ~Num_Node () { }

int Num_Node :: evaluate (void) const
{
    std::cout<<"Inside num node, n: " << n_ << std :: endl;
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