#ifndef CALCULATOR_BINARY_OP_COMMAND_H
#define CALCULATOR_BINARY_OP_COMMAND_H

#include "Expr_Node.h"
#include "Stack.h"

class Binary_Expr_Node : public Expr_Node
{
public:
    Binary_Expr_Node(void);
    virtual ~Binary_Expr_Node(void); //why is this destructor virtual?

    virtual int evaluate (void) const = 0;
protected:
    Expr_Node * right_;
    Expr_Node * left_;
}; //end Binary_Expr_Node

#endif //CALCULATOR_BINARY_OP_COMMAND_H