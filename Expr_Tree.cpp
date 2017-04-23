#include "Expr_Tree.h"

Expr_Tree :: Expr_Tree(Expr_Node * root)
{
    root_ = root;
} //end constructor

Expr_Tree :: ~Expr_Tree() { }

void Expr_Tree :: accept(Expr_Node_Visitor & v)
{
    root_->accept(v);
} //end accept