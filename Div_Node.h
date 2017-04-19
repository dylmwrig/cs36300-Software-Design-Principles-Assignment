#ifndef CALCULATOR_DIV_COMMAND_H
#define CALCULATOR_DIV_COMMAND_H

#include "Binary_Expr_Node.h"
#include "Stack.h"

class Div_Node : public Binary_Expr_Node
{
public:
    Div_Node();
    ~Div_Node();

    int evaluate (Num_Node * n1, Num_Node * n2) const;
    virtual void accept (Expr_Node_Visitor & v);
}; //end Div_Node

#endif //CALCULATOR_DIV_COMMAND_H