#ifndef CALCULATOR_MULT_COMMAND_H
#define CALCULATOR_MULT_COMMAND_H

#include "Binary_Expr_Node.h"

class Mult_Node : public Binary_Expr_Node
{
public:
    Mult_Node (void);
    Mult_Node(Expr_Node * left, Expr_Node * right);
    ~Mult_Node(void);

    int evaluate () const;
    virtual void accept (Expr_Node_Visitor & v);
}; //end Mult_Node

#endif //CALCULATOR_MULT_COMMAND_H