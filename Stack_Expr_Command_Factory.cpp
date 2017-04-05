#include "Stack_Expr_Command_Factory.h"
#include "Add_Node.h"
#include "Sub_Node.h"
#include "Num_Node.h"
#include "Div_Node.h"
#include "Paren_Command.h"

/*
//TODO overloaded constructor
Stack_Expr_Command_Factory :: Stack_Expr_Command_Factory(std::stack <int> & s)
{
    s_ = s;
} //end overloaded constructor
*/

Stack_Expr_Command_Factory :: ~Stack_Expr_Command_Factory()
{
    //makes me think that stack should be a pointer. Look into later
    //delete s_;
} //end destructor

Num_Node * Stack_Expr_Command_Factory :: create_number_command (int num)
{
    Num_Node * number = new Num_Node(s_, num);
    return number;
} //end create_number_command

Add_Node * Stack_Expr_Command_Factory :: create_add_command (void)
{
    Add_Node * adder = new Add_Node(s_);
    //Add_Node adder(s_);
    return adder;
} //end create_add_command

Sub_Node * Stack_Expr_Command_Factory :: create_subtract_command (void)
{
    Sub_Node * subtracter = new Sub_Node(s_);
    return subtracter;
} //end create_subtract_command

Div_Node * Stack_Expr_Command_Factory :: create_div_command (void)
{
    Div_Node * divider = new Div_Node(s_);
    return divider;
} //end create_div_command

Mult_Node * Stack_Expr_Command_Factory :: create_mult_command (void)
{
    Mult_Node * multiplier = new Mult_Node(s_);
    return multiplier;
} //end create_div_command

Paren_Command * Stack_Expr_Command_Factory :: create_paren_command (void)
{
    Paren_Command * parenthesis = new Paren_Command(s_);
    return parenthesis;
} //end create_paren_command

Modulus_Node * Stack_Expr_Command_Factory :: create_mod_command (void)
{
    Modulus_Node * mod = new Modulus_Node(s_);
    return mod;
} //end create_paren_command