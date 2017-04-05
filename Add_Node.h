#ifndef CALCULATOR_ADD_COMMAND_H
#define CALCULATOR_ADD_COMMAND_H

#include "Binary_Expr_Node.h"

class Add_Node : public Binary_Expr_Node
{
public:
    Add_Node (void);
    ~Add_Node(void);

    int evaluate (int n1, int n2) const;
}; //end Add_Node

#endif //CALCULATOR_ADD_COMMAND_H