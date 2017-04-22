#ifndef CALCULATOR_BINARY_EXPR_NODE_H
#define CALCULATOR_BINARY_EXPR_NODE_H

#include "Expr_Node.h"

class Binary_Expr_Node : public Expr_Node
{
public:
    Binary_Expr_Node(void);
    Binary_Expr_Node(Expr_Node * left, Expr_Node * right);
    virtual ~Binary_Expr_Node(void);

    virtual int evaluate (void) const = 0;
    virtual void accept (Expr_Node_Visitor & v) = 0;

    Expr_Node * left(void) const;
    Expr_Node * right(void) const;

protected:
    Expr_Node * right_;
    Expr_Node * left_;
}; //end Binary_Expr_Node

#endif //CALCULATOR_BINARY_EXPR_NODE_H