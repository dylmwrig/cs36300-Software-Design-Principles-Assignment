#ifndef CALCULATOR_PAREN_COMMAND_H
#define CALCULATOR_PAREN_COMMAND_H

#include "Unary_Expr_Node.h"

//class to represent the left parenthesis
//no need for a right parenthesis command
class Open_Paren_Node : public Unary_Expr_Node
{
public:
    Open_Paren_Node();

    int evaluate () const;
}; //end Open_Paren_Node

#endif //CALCULATOR_PAREN_COMMAND_H