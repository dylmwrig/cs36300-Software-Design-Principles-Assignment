#include "Mult_Node.h"
#include "Expr_Node_Visitor.h"

Mult_Node :: Mult_Node(void)
        :Binary_Expr_Node() { }

Mult_Node :: ~Mult_Node(void){ }

int Mult_Node :: evaluate () const
{
    //TODO temp
    return (1 * 1);
} //end evaluate


void Mult_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Mult_Node(*this);
} //end accept