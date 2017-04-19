#ifndef CALCULATOR_MODULUS_COMMAND_H
#define CALCULATOR_MODULUS_COMMAND_H


#include "Binary_Expr_Node.h"

class Modulus_Node : public Binary_Expr_Node
{
public:
    Modulus_Node(void);
    ~Modulus_Node(void);

    int evaluate (Num_Node * n1, Num_Node * n2) const;
    virtual void accept (Expr_Node_Visitor & v);
}; //end Modulus_Node

#endif //CALCULATOR_MODULUS_COMMAND_H