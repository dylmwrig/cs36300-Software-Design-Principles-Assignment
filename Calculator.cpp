#include <sstream>
#include "Calculator.h"
#include "Eval_Expr_Tree.h"
#include "Expr_Tree.h"

Calculator :: Calculator()
        : builder_() { }

Calculator :: ~Calculator() { }

bool Calculator :: isValid(std::string input)
{
    //increment parenCount when a left paren is encountered, decrement when a right paren is
    //if there is a matching closed parentheses to every open, it will equal 0 at the end
    int parenCount = 0;

    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
        {
            parenCount++;
        } //end if

        else if (input[i] == ')')
        {
            parenCount--;
        } //end else if
    } //end for

    if (parenCount == 0)
    {
        return true;
    } //end if

    return false;
} //end isValid

//perform the functions of a calculator
int Calculator :: calculate(std::string input)
{
    if (!isValid(input))
    {
        std::cout<<"Input is not valid.\n";
        return 0;
    } //end if

    builder_.start_expression(input);
    Expr_Tree * treeResult = builder_.get_expression();

    Eval_Expr_Tree * evaluator = new Eval_Expr_Tree();
    treeResult->accept(*evaluator);

    return evaluator->result();
} //end calculate