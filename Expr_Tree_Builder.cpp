#include "Expr_Tree_Builder.h"

virtual void Expr_Tree_Builder :: start_expression ()
{
    this->tree_ = new Expr_Tree ();
} //end start_expression

Expr_Tree * Expr_Tree_Builder :: get_expression (void)
{
    return this->tree_;
} //end getter