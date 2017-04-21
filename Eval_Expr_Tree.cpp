#include "Eval_Expr_Tree.h"

int Eval_Expr_Tree :: result (void) const
{
    return this->result_;
}

void Eval_Expr_Tree :: Visit_Add_Node (const Add_Node & node)
{
    result_ += node.evaluate();
} //end Visit_Add_Node

void Eval_Expr_Tree :: Visit_Sub_Node (const Sub_Node & node)
{
    result_ += node.evaluate();
} //end Visit_Add_Node

