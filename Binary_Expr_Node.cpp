#include "Binary_Expr_Node.h"

Binary_Expr_Node :: Binary_Expr_Node(void) { }

Binary_Expr_Node ::Binary_Expr_Node (Expr_Node * left, Expr_Node * right)
{
    left_ = left;
    right_ = right;
} //end overloaded constructor

Binary_Expr_Node :: ~Binary_Expr_Node(void) { }

Expr_Node * Binary_Expr_Node :: left(void) const
{
    return left_;
} //end getter

Expr_Node * Binary_Expr_Node :: right(void) const
{
    return right_;
} //end getter