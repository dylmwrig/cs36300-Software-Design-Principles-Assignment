#ifndef CALCULATOR_SUB_COMMAND_H
#define CALCULATOR_SUB_COMMAND_H

#include "Binary_Expr_Node.h"
#include "Num_Node.h"
#include "Stack.h"

class Sub_Node : public Binary_Expr_Node
{
public:
    Sub_Node();
    ~Sub_Node();

    int evaluate () const;
    virtual void accept (Expr_Node_Visitor & v);
}; //end Sub_Node

#endif //CALCULATOR_SUB_COMMAND_H