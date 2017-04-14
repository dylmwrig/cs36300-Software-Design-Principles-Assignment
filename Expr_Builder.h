#ifndef CALCULATOR2_EXPR_BUILDER_H
#define CALCULATOR2_EXPR_BUILDER_H


class Expr_Builder
{
public:
    virtual void start_expression (void);
    virtual void build_num (int n) = 0;
    virtual void build_add_operator (void) = 0;
    virtual void build_sub_operator (void) = 0;
    virtual void build_mult_operator (void) = 0;
    virtual void build_div_operator (void) = 0;
    virtual void build_mod_operator (void) = 0;
    virtual void build_open_paren (void) = 0;
    virtual void build_close_paren (void) = 0;
// get the current expression
    virtual Math_Expr * get_expression (void) = 0;
}; //end Expr_Builder

#endif //CALCULATOR2_EXPR_BUILDER_H
