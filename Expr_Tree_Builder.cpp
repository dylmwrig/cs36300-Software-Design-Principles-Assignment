#include <cstdlib> //atoi

#include "Expr_Tree_Builder.h"
#include "Num_Node.h"
#include "Expr_Tree.h"
#include "Paren_Content_Node.h"
#include "Sub_Node.h"
#include "Add_Node.h"
#include "Mult_Node.h"
#include "Div_Node.h"
#include "Modulus_Node.h"
#include "Eval_Expr_Tree.h"
#include "Calculator.h"

Expr_Tree_Builder :: Expr_Tree_Builder()
{
    //tree_ = 0; //this is how they handle member initialization for the builder pattern in the book
} //end constructor

Expr_Tree_Builder :: ~Expr_Tree_Builder()
{
    delete tree_;
} //end destructor

//check if the string is a number
bool numCheck(std::string input)
{
    for (int i = 0; i < input.size(); i++)
    {
        //return false if there is a single non number in the input
        if (!isdigit(input[i]))
        {
            return false;
        } //end if
    } //end for
    return true;
} //end numCheck

//I believe this is where input happens because there is no parameter for input
//
//construct a stack:
//-when the input token is an operand, push it to the stack
//-when the input token is an operator, pop two from the stack and make them the operator's children
//--push the operator onto the stack
//when you are done, the stack will only contain the root: construct the tree based on this root
void Expr_Tree_Builder :: start_expression (std::string input)
{
    std::string postfix = infixToPostfix(input);

    std::string nodeInput = "";
    for (size_t i = 0; i < postfix.size(); i++)
    {
        if (i == postfix.size() - 1 && postfix[i] != ' ')
        {
            nodeInput = postfix[i];
        } //end if

        if (postfix[i] == ' ')
        {
            if (numCheck(nodeInput))
            {
                build_num(atoi(nodeInput.c_str()));
            } //end if

            else if (nodeInput == "+")
            {
                build_add_operator();
            } //end else if

            else if (nodeInput == "-")
            {
                build_sub_operator();
            } //end else if

            else if (nodeInput == "*")
            {
                build_mult_operator();
            } //end else if

            else if (nodeInput == "/")
            {
                build_div_operator();
            } //end else if

            else if (nodeInput == "%")
            {
                build_mod_operator();
            } //end else if

            else if (nodeInput == "(")
            {
                bool parenCheck = true;
                int parenCount = 0;
                Calculator calculator;
                std::string splitInput = "";
                i++;

                while (parenCheck)
                {
                    if (nodeInput[i] == '(')
                    {
                        parenCount++;
                    } //end if

                    else if (nodeInput[i] == ')')
                    {
                        if (parenCount == 0)
                        {
                            parenCheck = false;
                        } //end if

                        else
                        {
                            parenCount--;
                        } //end else
                    } //end else if

                    splitInput += nodeInput[i];
                    i++;
                } //end while

                i++; //move the index past the final )
                build_paren(splitInput);
            } //end else if

            nodeInput = "";
        } //end if

        else
        {
            nodeInput += postfix[i];
        } //end else
    } //end for

    tree_ = new Expr_Tree(nodes.top());
    nodes.pop();
} //end start_expression

//convert an infix expression to postfix and return the postfix translation
//complete the conversion using a stack
//
//return a postfix representation of the input with each piece of the expression separated by spaces
std::string Expr_Tree_Builder :: infixToPostfix(std::string infix)
{
    std :: string input = "", output = "";
    Stack <std::string> operators;

    for (size_t i = 0; i < infix.size(); i++)
    {
        //clunky way of catching the last character
        if (i == infix.size() - 1 && infix[i] != ' ')
        {
            input = infix[i];
        } //end if

        //move through the string character by character, splitting based on spaces
        //each piece of the equation will be split by a space, this accounts for negative numbers
        //and numbers which are two digits or longer
        if (infix[i] == ' ' || i == infix.size() - 1)
        {
            //keep each parentheses bit in its place as we'll take care of that later
            if (input == "(")
            {
                bool insideParen = true;
                int parenCount = 0;

                while (insideParen)
                {

                    if (infix[i] == '(')
                    {
                        parenCount++;
                    } //end if

                    else if (infix[i] == ')')
                    {
                        if (parenCount == 0)
                        {
                            insideParen = false;
                        } //end if

                        else
                        {
                            parenCount--;
                        } //end else
                    } //end else if

                    i++;
                } //end while
            } //end if

            //numbers are immediately added to the output
            if (numCheck(input))
            {
                output += input + " ";
            } //end if

            else
            {
                if (input != ")")
                {
                    if (input == "+" || input == "-")
                    {
                        while (!operators.is_empty() && operators.top() != "(" && operators.top() != ")")
                        {
                            output += operators.top() + " ";
                            operators.pop();
                        } //end while
                    } //end if

                        //is this the correct precedence for modulus?
                    else if (input == "*" || input == "/" || input == "%")
                    {
                        while (!operators.is_empty() && operators.top() != "(" && operators.top() != ")" &&
                               operators.top() != "+" && operators.top() != "-")
                        {
                            output += operators.top()  + " ";
                            operators.pop();
                        } //end while
                    } //end else if

                    //no need to check if the parentheses count is correct again, because this is already done
                    else if (input == "(")
                    {
                        int parenCount = 0;
                        Calculator calculator;
                        std::string splitInput = "";

                        for (int j = i + 1; j < infix.size(); j++)
                        {
                            if (infix[j] == '(')
                            {
                                parenCount++;
                            } //end if

                            else if (infix[j] == ')')
                            {
                                if (parenCount == 0)
                                {
                                    calculator.calculate(splitInput);
                                } //end if

                                else
                                {
                                    parenCount--;
                                } //end else
                            } //end if

                            splitInput += infix[j];
                        } //end for
                    } //end else if

                    operators.push(input);
                } //end else if

                else
                {
                    operators.pop(); //pop the left parenthesis now
                } //end else

            } //end if
            input = ""; //reset the input string
        } //end if
    } //end for

    //clear out the rest of the stack
    while (!operators.is_empty())
    {
        output += operators.top() + " ";
        operators.pop();
    } //end while

    return output;
} //end infixToPostfix

Expr_Tree * Expr_Tree_Builder :: get_expression (void)
{
    return this->tree_;
} //end getter

//builders which add each operation to the expression tree
void Expr_Tree_Builder :: build_num(int n)
{
    Num_Node * toAdd = new Num_Node(n);
    nodes.push(toAdd);
} //end build_num

void Expr_Tree_Builder :: build_paren(std::string subExpression)
{
    Paren_Content_Node * toAdd = new Paren_Content_Node(subExpression);
    nodes.push(toAdd);
} //end build_paren

void Expr_Tree_Builder :: build_add_operator()
{
    Expr_Node * left = nodes.top();
    nodes.pop();
    Expr_Node * right = nodes.top();
    nodes.pop();
    Add_Node * toAdd = new Add_Node(left, right);
    nodes.push(toAdd);
} //end build_add_operator

void Expr_Tree_Builder :: build_sub_operator()
{
    Expr_Node * left = nodes.top();
    nodes.pop();
    Expr_Node * right = nodes.top();
    nodes.pop();
    Sub_Node * toAdd = new Sub_Node(left, right);
    nodes.push(toAdd);
} //end build_sub_operator

void Expr_Tree_Builder :: build_mult_operator()
{
    Expr_Node * left = nodes.top();
    nodes.pop();
    Expr_Node * right = nodes.top();
    nodes.pop();
    Mult_Node * toAdd = new Mult_Node(left, right);
    nodes.push(toAdd);
} //end build_mult_operator

void Expr_Tree_Builder ::build_div_operator()
{
    Expr_Node * left = nodes.top();
    nodes.pop();
    Expr_Node * right = nodes.top();
    nodes.pop();
    Div_Node * toAdd = new Div_Node(left, right);
    nodes.push(toAdd);
} //end build_div_operator

void Expr_Tree_Builder :: build_mod_operator()
{
    Expr_Node * left = nodes.top();
    nodes.pop();
    Expr_Node * right = nodes.top();
    nodes.pop();
    Modulus_Node * toAdd = new Modulus_Node(left, right);
    nodes.push(toAdd);
} //end build_mod_operator