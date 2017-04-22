#include <cstdlib> //atoi

#include "Expr_Tree_Builder.h"
#include "Num_Node.h"
#include "Expr_Tree.h"
#include "Open_Paren_Node.h"
#include "Close_Paren_Node.h"
#include "Sub_Node.h"
#include "Add_Node.h"
#include "Mult_Node.h"
#include "Div_Node.h"
#include "Modulus_Node.h"

Expr_Tree_Builder :: Expr_Tree_Builder()
{
    tree_ = 0; //this is how they handle member initialization for the builder pattern in the book
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
void Expr_Tree_Builder :: start_expression ()
{
    this->tree_ = new Expr_Tree ();

    std::stack <Expr_Node> s;
    //TODO
    //input stuff
    std::string input = "3 + 5 * 2 / 1";

    std::cout<<input<<std::endl;
    std::string postfix = infixToPostfix(input);
    std::cout<<postfix<<std::endl;

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

            nodeInput = "";
        } //end if

        else
        {
            nodeInput += postfix[i];
        } //end else
    } //end for

    /*
    //taken from driver
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
     */
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

                        //TODO
                    else if (input == "(")
                    {
                        //Expr_Node *cmd = factory.create_paren_command();
                    } //end else if

                    operators.push(input);
                } //end else if

                    //right parenth is the only special case
                else
                {
                    //TODO
                    operators.pop(); //pop the left parenthesis now
                } //end else

            } //end if
            input = ""; //reset the input string
        } //end if

        //if the input is not a space, add it to the input string (useful for two digit and above numbers)
        else
        {
            input += infix[i];
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
    //tree_->add(toAdd);
} //end build_num

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
    Sub_Node * toAdd = new Sub_Node();
    //tree_->add(toAdd);
} //end build_sub_operator

void Expr_Tree_Builder :: build_mult_operator()
{
    Mult_Node * toAdd = new Mult_Node();
    //tree_->add(toAdd);
} //end build_mult_operator

void Expr_Tree_Builder ::build_div_operator()
{
    Div_Node * toAdd = new Div_Node();
    //tree_->add(toAdd);
} //end build_div_operator

void Expr_Tree_Builder :: build_mod_operator()
{
    Modulus_Node * toAdd = new Modulus_Node();
    //tree_->add(toAdd);
} //end build_mod_operator

void Expr_Tree_Builder :: build_open_paren()
{
    Open_Paren_Node * toAdd = new Open_Paren_Node();
    //tree_->add(toAdd);
} //end build_open_parem

void Expr_Tree_Builder ::build_close_paren()
{
    Close_Paren_Node * toAdd = new Close_Paren_Node();
    //tree_->add(toAdd);
} //end build_close_paren