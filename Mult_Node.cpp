#include "Mult_Node.h"

Mult_Node :: Mult_Node(void)
        :Binary_Expr_Node() { }

Mult_Node :: ~Mult_Node(void){ }

int Mult_Node :: evaluate (int n1, int n2) const
{
    return (n1 * n2);
} //end evaluate