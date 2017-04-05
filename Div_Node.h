#ifndef CALCULATOR_DIV_COMMAND_H
#define CALCULATOR_DIV_COMMAND_H

#include "Binary_Expr_Node.h"
#include "Stack.h"

class Div_Node : public Binary_Expr_Node
{
public:
    Div_Node();
    ~Div_Node();

    int evaluate (int n1, int n2) const;
}; //end Div_Node

#endif //CALCULATOR_DIV_COMMAND_H