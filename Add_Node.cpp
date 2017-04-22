#include <iostream>
#include "Add_Node.h"
#include "Expr_Node_Visitor.h" //TODO CIRCULAR DEPENDENCY

Add_Node :: Add_Node(void)
                :Binary_Expr_Node(){ }

Add_Node :: Add_Node(Expr_Node * left, Expr_Node * right)
                :Binary_Expr_Node(left, right) { }

Add_Node :: ~Add_Node(void) { }

int Add_Node :: evaluate (void) const
{
    int n1 = left_->evaluate();
    int n2 = right_->evaluate();
    std::cout<<"Inside add node, n1 then n2: " << n1 << " " << n2 << std :: endl;

    return (n1 + n2);
} //end evaluate

void Add_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Add_Node(*this);
} //end accept