#ifndef CALCULATOR_VARIABLE_COMMAND_H
#define CALCULATOR_VARIABLE_COMMAND_H

#include "Num_Node.h"

class Variable_Command : public Num_Node
{
public:
    Variable_Command(Stack <int> & s);
    void setValue(int val);

}; //end Variable_Command

#endif //CALCULATOR_VARIABLE_COMMAND_H