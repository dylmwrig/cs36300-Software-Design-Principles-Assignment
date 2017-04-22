#ifndef CALCULATOR_SUB_COMMAND_H
#define CALCULATOR_SUB_COMMAND_H

#include "Binary_Expr_Node.h"

class Sub_Node : public Binary_Expr_Node
{
public:
    Sub_Node(void);
    Sub_Node(Expr_Node * left, Expr_Node * right);
    ~Sub_Node(void);

    int evaluate (void) const;
    virtual void accept (Expr_Node_Visitor & v);
}; //end Sub_Node

#endif //CALCULATOR_SUB_COMMAND_H