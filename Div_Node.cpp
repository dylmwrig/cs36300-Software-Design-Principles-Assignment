#include "Div_Node.h"

Div_Node ::Div_Node(void)
        :Binary_Expr_Node() { }

Div_Node :: ~Div_Node(void){ }

int Div_Node :: evaluate (Num_Node * n1, Num_Node * n2) const
{
    //do not divide by zero
    if (n2->evaluate() == 0)
    {
        std::cout<<"Unable to perform division due to divide by zero"<<std::endl;
        return 0;
    } //end if

    else
    {
        return (n1->evaluate() / n2->evaluate());
    } //end else
} //end evaluate

virtual void Div_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Div_Node(*this);
} //end accept