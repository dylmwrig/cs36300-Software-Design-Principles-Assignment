#ifndef CALCULATOR_ADD_COMMAND_H
#define CALCULATOR_ADD_COMMAND_H

#include "Binary_Expr_Node.h"

class Add_Node : public Binary_Expr_Node
{
public:
    Add_Node (void);
    Add_Node (Expr_Node * left, Expr_Node * right);
    virtual ~Add_Node(void);

    virtual int evaluate () const;
    virtual void accept (Expr_Node_Visitor & v);
}; //end Add_Node

#endif //CALCULATOR_ADD_COMMAND_H