#include "Modulus_Node.h"

Modulus_Node :: Modulus_Node(void)
        :Binary_Expr_Node(){ }

Modulus_Node :: ~Modulus_Node(void){ }

int Modulus_Node :: evaluate (int n1, int n2) const
{
    return (n1 % n2);
} //end evaluate

virtual void Modulus_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Mod_Node(*this);
} //end accept