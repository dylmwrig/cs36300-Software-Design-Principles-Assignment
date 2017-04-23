#ifndef CALCULATOR2_CALCULATOR_H
#define CALCULATOR2_CALCULATOR_H

#include <iostream>
#include "Expr_Tree_Builder.h"

//a driver, basically
class Calculator
{
public:
    Calculator(void);
    ~Calculator(void);

    bool calculate(std::string input);

private:
    bool isValid(std::string input);
    Expr_Tree_Builder builder_;
}; //end Calculator


#endif //CALCULATOR2_CALCULATOR_H
