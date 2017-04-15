#ifndef CALCULATOR_EXPR_COMMAND_FACTORY_H
#define CALCULATOR_EXPR_COMMAND_FACTORY_H

#include "Add_Node.h"
#include "Sub_Node.h"
#include "Num_Node.h"
#include "Div_Node.h"
#include "Mult_Node.h"
#include "Open_Paren_Node.h"
#include "Modulus_Node.h"

class Expr_Command_Factory
{
public:
    Expr_Command_Factory(void) { }
    virtual ~Expr_Command_Factory() { } //proper way to declare abstract destructor

    virtual Num_Node * create_number_command (int num) = 0;
    virtual Add_Node * create_add_command (void) = 0;
    virtual Sub_Node * create_subtract_command (void) = 0;
    virtual Div_Node * create_div_command (void) = 0;
    virtual Mult_Node * create_mult_command (void) = 0;
    virtual Paren_Command * create_paren_command (void) = 0;
    virtual Modulus_Node * create_mod_command (void) = 0;

private:
    // prevent the following operations
    Expr_Command_Factory (const Expr_Command_Factory & ex);
    const Expr_Command_Factory & operator = (const Expr_Command_Factory & ex);
}; //end Expr_Command_Factory
#endif //CALCULATOR_EXPR_COMMAND_FACTORY_H
