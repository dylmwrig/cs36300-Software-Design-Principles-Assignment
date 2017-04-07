#include "Mult_Node.h"

Mult_Node :: Mult_Node(void)
        :Binary_Expr_Node() { }

Mult_Node :: ~Mult_Node(void){ }

int Mult_Node :: evaluate (int n1, int n2) const
{
    return (n1 * n2);
} //end evaluate


virtual void Mult_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Mult_Node(*this);
} //end accept