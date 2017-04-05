#include "Add_Node.h"

Add_Node :: Add_Node(void)
        :Binary_Expr_Node(){ }

Add_Node :: ~Add_Node(void) { }

int Add_Node :: evaluate (int n1, int n2) const
{
    return (n1 + n2);
} //end evaluate