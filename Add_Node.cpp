#include "Add_Node.h"

Add_Node :: Add_Node(void)
        :Binary_Expr_Node(){ }

Add_Node :: ~Add_Node(void) { }

int Add_Node :: evaluate (Num_Node * n1, Num_Node * n2) const
{
    return (n1->evaluate() + n2->evaluate());
} //end evaluate

virtual void Add_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Add_Node(*this);
} //end accept