#ifndef CALCULATOR_MODULUS_COMMAND_H
#define CALCULATOR_MODULUS_COMMAND_H


#include "Binary_Expr_Node.h"

class Modulus_Node : public Binary_Expr_Node
{
public:
    Modulus_Node(void);
    ~Modulus_Node(void);

    int evaluate (int n1, int n2) const;
}; //end Modulus_Node

#endif //CALCULATOR_MODULUS_COMMAND_H