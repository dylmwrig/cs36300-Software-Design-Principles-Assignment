#include "Expr_Tree_Builder.h"

Expr_Tree_Builder :: Expr_Tree_Builder() : tree_() { }

~Expr_Tree_Builder :: Expr_Tree_Builder()
{
    delete tree_;
} //end destructor

virtual void Expr_Tree_Builder :: start_expression ()
{
    this->tree_ = new Expr_Tree ();
} //end start_expression

Expr_Tree * Expr_Tree_Builder :: get_expression (void)
{
    return this->tree_;
} //end getter

//builders which add each operation to the expression tree
virtual void Expr_Tree_Builder :: build_num(int n)
{
    Num_Node toAdd = Num_Node(n);
    tree_.add(toAdd);
} //end build_num

virtual void Expr_Tree_Builder :: build_add_operator()
{
    Add_Node toAdd = Add_Node();
    tree_.add(toAdd);
} //end build_num

virtual void Expr_Tree_Builder :: build_sub_operator()
{
    Sub_Node toAdd = Sub_Node();
    tree_.add(toAdd);
} //end build_num

virtual void Expr_Tree_Builder :: build_mult_operator()
{
    Mult_Node toAdd = Mult_Node(n);
    tree_.add(toAdd);
} //end build_num

virtual void Expr_Tree_Builder ::build_div_operator()
{
    Div_Node toAdd = Div_Node(n);
    tree_.add(toAdd);
} //end build_num

virtual void Expr_Tree_Builder :: build_mod_operator()
{
    Modulus_Node toAdd = Modulus_Node(n);
    tree_.add(toAdd);
} //end build_num

/*
virtual void Expr_Tree_Builder :: build_open_paren()
{
    Left_Paren_Node toAdd = Left_Paren_Node(n);
    tree_.add(toAdd);
} //end build_num
 */