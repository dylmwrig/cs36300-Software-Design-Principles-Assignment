#include <iostream>
#include <vector>
#include <ctype.h> //isdigit
#include <cstdlib>
#include <map>
#include "Array.h"
#include "Array_Iterator.h"
#include "Stack.h"
#include "Expr_Node.h"
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"
#include "Add_Node.h"
#include "Sub_Node.h"
#include "Mult_Node.h"
#include "Num_Node.h"
#include "Div_Node.h"
//#include "Variable_Command.h"

//I realize it's weird to put a function in a driver file but I'm just doing this for now
//until I find a proper home for the poor thing.
//
//check a string input. If an integer, return a 0
//if a string, return a 1
//if neither, it is a symbol (like +) or it is undefined, return a 2
int inputCheck(std::string toCheck)
{
    int rtn = -1;

    bool isInt = true, isAlpha = true;
    for (int i = 0; i <toCheck.length(); i++)
    {
        if (!isdigit((toCheck)[i]))
        {
            isInt = false;
        } //end if

        if (!isalpha((toCheck)[i]))
        {
            isAlpha = false;
        } //end if
    } //end for

    if (isInt)
    {
        rtn = 0;
    } //end if

    else if (isAlpha)
    {
        rtn = 1;
    } //end else if

        //otherwise, the input is an operator or undefined
    else
    {
        rtn = 2;
    } //end else

    return rtn;
} //end inputCheck

//convert the expression from infix to postfix
Array<Expr_Node *> postfix(Array<std::string> expressions, Stack_Expr_Command_Factory & factory)
{
    std :: string input = "", stackResult = "";
    Stack <Expr_Node *> operators;
    Array<Expr_Node *> postfix;

    for (size_t i = 0; i < expressions.size(); i ++)
    {
        input = expressions[i];

        if (inputCheck(input) == 0)
        {
            Num_Node * number = factory.create_number_command(atoi(input.c_str()));
            postfix.add(number);
        } //end if

        else if (input != ")")
        {
            Expr_Node *cmd;
            if (input == "+")
            {
                cmd = factory.create_add_command();
            } //end if

            else if (input == "-")
            {
                cmd = factory.create_subtract_command();
            } //end else if

            else if (input == "*")
            {
                cmd = factory.create_mult_command();
            } //end else if

            else if (input == "/")
            {
                cmd = factory.create_div_command();
            } //end else if

            else if (input == "%")
            {
                cmd = factory.create_mod_command();
            } //end else if

            else if (input == "(")
            {
                Expr_Node *cmd = factory.create_paren_command();
            } //end else if

            while (!operators.is_empty() && (operators.top()->getPrecedence() >= cmd->getPrecedence()))
            {
                postfix.add(operators.top());
                operators.pop();
            } //end while

            operators.push(cmd);
        } //end else if

        //right parenth is the only special case
        else
        {
            while (operators.top()->getPrecedence() != -1) //while this is not a left parenthesis: I realize this is brittle
            {
                postfix.add(operators.top());
                operators.pop();
            } //end while

            operators.pop(); //pop the left parenthesis now
        } //end else
    } //end for

    //clear out the rest of the stack
    while (!operators.is_empty())
    {
        postfix.add(operators.top());
        operators.pop();
    } //end while

    return postfix;
} //end postfix

int main()
{
    /*
    Stack <int> s;
    Stack_Expr_Command_Factory factory(s);
    Array<std::string> inputs;
    std::string input = "";
    std::string expression = "";
    int lineCount = 0;

    while (input != "QUIT")
    {
        std :: cout << lineCount << "\tPlease enter your expression: ";
        std :: getline (std::cin,input);
        if (input != "QUIT")
        {
            for (char c : input)
            {
                if (c != ' ')
                {
                    if (isalpha(c))
                    {
                      //std :: cout << "\n" << c << "=";
                      //int value = 0;
                      //std :: cin >> value;
                      //std :: string s = std :: to_string(value);
                      //std :: cout << std::endl << "number to be added: " << s << std :: endl;
                      //expression += s;

                    } //end if

                    else
                    {
                      expression += c;
                    } //end else
                } //end if

                else
                {
                    //Expr_Node command;
                  
                    //expressions.push_back(command);
                    inputs.add(expression);
                    expression = "";
                } //end else
            } //end for
            inputs.add(expression);
	        expression = "";
            lineCount++;
        } //end if
    } //end while

    Array <Expr_Node * > postfixArr = postfix(inputs, factory);
    for (int i = 0; i < postfixArr.size(); i++)
    {
        postfixArr[i]->execute();
    }
    std::cout<<s.top();
    */

    return 0;
} //end main