#ifndef CALCULATOR_EXPR_COMMAND_H
#define CALCULATOR_EXPR_COMMAND_H

#include <stack>

#include "Stack.h"
#include "Expr_Node_Visitor.h"

//pure virtual class for each kind of command to inherit from
class Expr_Node
{
public:
    Expr_Node (void);
    ~Expr_Node(void);

    virtual int evaluate (void) = 0;
    virtual void accept (Expr_Node_Visitor & v) = 0; //used for traversal using visitor class

protected:
    Expr_Node * child_;
}; //end Expr_Node

#endif //CALCULATOR_EXPR_COMMAND_H