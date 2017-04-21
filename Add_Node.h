#ifndef CALCULATOR_ADD_COMMAND_H
#define CALCULATOR_ADD_COMMAND_H

#include "Binary_Expr_Node.h"
//#include "Num_Node.h"
//#include "Expr_Node_Visitor.h"
//class Binary_Expr_Node;

class Add_Node : public Binary_Expr_Node
{
public:
    Add_Node (void);
    ~Add_Node(void);

    int evaluate () const;
    virtual void accept (Expr_Node_Visitor & v);
}; //end Add_Node

#endif //CALCULATOR_ADD_COMMAND_H