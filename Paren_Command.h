#ifndef CALCULATOR_PAREN_COMMAND_H
#define CALCULATOR_PAREN_COMMAND_H

#include "Binary_Expr_Node.h"

//class to represent the left parenthesis
//no need for a right parenthesis command
class Paren_Command : public Binary_Expr_Node
{
public:
    Paren_Command(Stack <int> & s);

    int evaluate (int n1, int n2) const;
}; //end Paren_Command

#endif //CALCULATOR_PAREN_COMMAND_H