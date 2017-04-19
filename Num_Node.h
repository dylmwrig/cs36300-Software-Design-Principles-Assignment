#ifndef CALCULATOR_NUM_COMMAND_H
#define CALCULATOR_NUM_COMMAND_H

#include "Stack.h"
#include "Expr_Node.h"
#include <string>

class Num_Node : public Expr_Node
{
public:
    Num_Node (int n);
    ~Num_Node(void);
    int evaluate (void);
    virtual void accept(Expr_Node_Visitor & v);
protected:
    int n_;
}; //end Num_Node

#endif //CALCULATOR_NUM_COMMAND_H