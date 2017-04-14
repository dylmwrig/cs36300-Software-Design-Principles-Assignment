#ifndef CALCULATOR2_EXPR_TREE_BUILDER_H
#define CALCULATOR2_EXPR_TREE_BUILDER_H

#include "Expr_Builder.h"

class Expr_Tree_Builder : public Expr_Builder
{
public:
    Expr_Tree_Builder (void);
    virtual ~Expr_Builder_Tree (void);
    virtual void start_expression (void);
    virtual void build_num (int n);
    virtual void build_add_operator (void);
    virtual void build_sub_operator (void);
    virtual void build_mult_operator (void);
    virtual void build_div_operator (void);
    virtual void build_mod_operator (void);

    //TODO
    //we need both open and close paren objects? Was that mentioned in class? Might want to look through notes
    virtual void build_open_paren (void);
    virtual void build_close_paren (void);
    Expr_Tree * get_expression (void);
private:
// current state of expression tree
    Expr_Tree * tree_;
// other variables to coordinate build process
}; //end Expr_Tree_Builder

#endif //CALCULATOR2_EXPR_TREE_BUILDER_H
