#ifndef CALCULATOR_NUM_COMMAND_H
#define CALCULATOR_NUM_COMMAND_H

#include "Stack.h"
#include "Expr_Node.h"
#include <string>

class Num_Node : public Expr_Node
{
public:
    Num_Node (int n);
    bool execute (void);
protected:
    int n_;
}; //end Num_Node

#endif //CALCULATOR_NUM_COMMAND_H