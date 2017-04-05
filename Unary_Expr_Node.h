#ifndef CALCULATOR2_UNARY_EXPR_NODE_H
#define CALCULATOR2_UNARY_EXPR_NODE_H


#include "Expr_Node.h"

class Unary_Expr_Node : public Expr_Node {
public:
    Unary_Expr_Node (void);
    virtual ~Unary_Expr_Node (void);
    virtual int evaluate (void);

protected:
    Expr_Node * child_;
}; //end Unary_Expr_Node

#endif //CALCULATOR2_UNARY_EXPR_NODE_H
