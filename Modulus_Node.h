#ifndef CALCULATOR_MODULUS_COMMAND_H
#define CALCULATOR_MODULUS_COMMAND_H

#include "Binary_Expr_Node.h"
class Expr_Node_Visitor;

class Modulus_Node : public Binary_Expr_Node
{
public:
    Modulus_Node(void);
    ~Modulus_Node(void);

    int evaluate () const;
    virtual void accept (Expr_Node_Visitor & v);
}; //end Modulus_Node

#endif //CALCULATOR_MODULUS_COMMAND_H