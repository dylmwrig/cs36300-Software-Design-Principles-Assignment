#include "Modulus_Node.h"
#include "Expr_Node_Visitor.h"

Modulus_Node :: Modulus_Node(void)
        :Binary_Expr_Node(){ }

Modulus_Node :: Modulus_Node(Expr_Node * left, Expr_Node * right)
                :Binary_Expr_Node(left, right) { }

Modulus_Node :: ~Modulus_Node(void){ }

int Modulus_Node :: evaluate () const
{
    int n1 = left_->evaluate();
    int n2 = right_->evaluate();

    return (n1 % n2);
} //end evaluate

void Modulus_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Mod_Node(*this);
} //end accept