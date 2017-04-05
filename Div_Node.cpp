#include "Div_Node.h"

Div_Node ::Div_Node(void)
        :Binary_Expr_Node() { }

Div_Node :: ~Div_Node(void){ }

int Div_Node :: evaluate (int n1, int n2) const
{
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