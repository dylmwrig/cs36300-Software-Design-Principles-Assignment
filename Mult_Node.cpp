#include <iostream>
#include "Mult_Node.h"
#include "Expr_Node_Visitor.h"

Mult_Node :: Mult_Node(void)
        :Binary_Expr_Node() { }

Mult_Node :: Mult_Node(Expr_Node * left, Expr_Node * right)
                :Binary_Expr_Node(left, right) { }

Mult_Node :: ~Mult_Node(void){ }

int Mult_Node :: evaluate () const
{
    int n1 = left_->evaluate();
    int n2 = right_->evaluate();

    std::cout<<"Inside mult node, n1 then n2: " << n1 << " " << n2 << std :: endl;

    return (n1 * n2);
} //end evaluate


void Mult_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Mult_Node(*this);
} //end accept