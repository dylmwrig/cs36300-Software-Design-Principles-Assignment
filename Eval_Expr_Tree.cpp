#include "Eval_Expr_Tree.h"
#include "Add_Node.h"
#include "Sub_Node.h"
#include "Mult_Node.h"
#include "Div_Node.h"
#include "Modulus_Node.h"

Eval_Expr_Tree :: Eval_Expr_Tree (void) { }

Eval_Expr_Tree :: ~Eval_Expr_Tree (void) { }

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
} //end Visit_Sub_Node


void Eval_Expr_Tree :: Visit_Mult_Node (const Mult_Node & node)
{
    //result_ += node.evaluate();
} //end Visit_Mult_Node

void Eval_Expr_Tree :: Visit_Div_Node (const Div_Node & node)
{
    //result_ += node.evaluate();
} //end Visit_Div_Node

void Eval_Expr_Tree :: Visit_Mod_Node (const Modulus_Node & node)
{
    //result_ += node.evaluate();
} //end Visit_Mod_Node

void Eval_Expr_Tree :: Visit_Num_Node (const Num_Node & node)
{
    //result_ += node.evaluate();
} //end Visit_Num_Node