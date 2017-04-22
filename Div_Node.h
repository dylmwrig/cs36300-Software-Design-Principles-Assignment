#ifndef CALCULATOR_DIV_COMMAND_H
#define CALCULATOR_DIV_COMMAND_H

#include "Binary_Expr_Node.h"
#include "Stack.h"

class Div_Node : public Binary_Expr_Node
{
public:
    Div_Node();
    Div_Node(Expr_Node * left, Expr_Node * right);
    ~Div_Node();

    int evaluate () const;
    virtual void accept (Expr_Node_Visitor & v);
}; //end Div_Node

#endif //CALCULATOR_DIV_COMMAND_H