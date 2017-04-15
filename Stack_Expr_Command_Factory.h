#ifndef CALCULATOR_STACK_EXPR_COMMAND_FACTORY_H
#define CALCULATOR_STACK_EXPR_COMMAND_FACTORY_H

#include "Stack.h"
#include "Expr_Command_Factory.h"

class Stack_Expr_Command_Factory : Expr_Command_Factory
{
public:
    //Stack_Expr_Command_Factory(void);
    //explicit Stack_Expr_Command_Factory(std::stack <int> & s)
    //should this be not explicit? I'm going to leave it as is for now
    Stack_Expr_Command_Factory(Stack <int> & s) : s_ (s) { }

    virtual ~Stack_Expr_Command_Factory ();

    virtual Num_Node * create_number_command (int num);
    virtual Add_Node * create_add_command (void);
    virtual Sub_Node * create_subtract_command (void);
    virtual Div_Node * create_div_command (void);
    virtual Mult_Node * create_mult_command(void);
    virtual Open_Paren_Node * create_paren_command(void);
    virtual Modulus_Node * create_mod_command(void);
private:
    Stack <int> & s_;
};

#endif //CALCULATOR_STACK_EXPR_COMMAND_FACTORY_H
