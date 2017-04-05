#ifndef CALCULATOR_EXPR_COMMAND_H
#define CALCULATOR_EXPR_COMMAND_H

#include <stack>

#include "Stack.h"

//pure virtual class for each kind of command to inherit from
class Expr_Node
{
public:
    Expr_Node (void);
    ~Expr_Node(void);

    virtual int evaluate (void) = 0;

protected:
    Expr_Node * child_;
}; //end Expr_Node

#endif //CALCULATOR_EXPR_COMMAND_H