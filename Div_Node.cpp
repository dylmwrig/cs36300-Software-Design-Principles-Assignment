#include "Div_Node.h"
#include "Expr_Node_Visitor.h"

Div_Node ::Div_Node(void)
        :Binary_Expr_Node() { }

Div_Node :: Div_Node(Expr_Node * left, Expr_Node * right)
        :Binary_Expr_Node(left, right) { }

Div_Node :: ~Div_Node(void){ }

int Div_Node :: evaluate () const
{
    int n1 = left_->evaluate();
    int n2 = right_->evaluate();

    std::cout<<"Inside div node, n1 then n2: " << n1 << " " << n2 << std :: endl;

    //do not divide by zero
    if (n2 == 0)
    {
        std::cout<<"Unable to perform division due to divide by zero"<<std::endl;
        return 0;
    } //end if

    else
    {
        return (n1 / n2);
    } //end else
} //end evaluate

void Div_Node :: accept (Expr_Node_Visitor & v)
{
    v.Visit_Div_Node(*this);
} //end accept