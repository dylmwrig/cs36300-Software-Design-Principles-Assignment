#ifndef CALCULATOR2_EXPR_TREE_BUILDER_H
#define CALCULATOR2_EXPR_TREE_BUILDER_H

#include "Expr_Builder.h"
#include "Expr_Tree.h"

//builder for the expression tree
//parse the infix expression and construct nodes for the tree based on that
//the builder pattern seen here is also utilizing the composite pattern
//in that each binary node will take its child nodes into the expression, so each node is essentially
//a composite of other nodes
//          +
//       -     *
//     +   2  1  5
//   1   2
//going off of the above "diagram", take a look at the subtraction node. It will take in a two, and the result
//of the addition with other number nodes and feed that into the addition node above it. In this way
//the expressions components are making composites of each other
class Expr_Tree_Builder : public Expr_Builder
{
public:
    Expr_Tree_Builder (void);
    virtual ~Expr_Tree_Builder (void);
    virtual void start_expression (void);
    virtual void build_num (int n);
    virtual void build_add_operator (void);
    virtual void build_sub_operator (void);
    virtual void build_mult_operator (void);
    virtual void build_div_operator (void);
    virtual void build_mod_operator (void);
    virtual void build_open_paren (void);
    virtual void build_close_paren (void);
    Expr_Tree * get_expression (void);
private:
// current state of expression tree
    Expr_Tree * tree_;
// other variables to coordinate build process
}; //end Expr_Tree_Builder

#endif //CALCULATOR2_EXPR_TREE_BUILDER_H
