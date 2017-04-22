#ifndef CALCULATOR_PAREN_COMMAND_H
#define CALCULATOR_PAREN_COMMAND_H

#include "Unary_Expr_Node.h"

//class to represent the left parenthesis
//no need for a right parenthesis command
class Open_Paren_Node : public Unary_Expr_Node
{
public:
    Open_Paren_Node(void);
    ~Open_Paren_Node(void);

    int evaluate (void) const;
    virtual void accept (Expr_Node_Visitor & v);
}; //end Open_Paren_Node

#endif //CALCULATOR_PAREN_COMMAND_H