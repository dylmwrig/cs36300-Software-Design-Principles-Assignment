#include "Variable_Command.h"

//call the parent constructor with 0 passed in for the number
//because the value is yet to be set
Variable_Command :: Variable_Command(Stack<int> & s)
            :Num_Node(s, 0){ }

//set the value of the parent number command
void Variable_Command :: setValue(int val)
{
    n_ = val;
} //end setValue