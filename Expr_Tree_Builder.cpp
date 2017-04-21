#include "Expr_Tree_Builder.h"
#include "Num_Node.h"
#include "Expr_Tree.h"
#include "Open_Paren_Node.h"
#include "Close_Paren_Node.h"

Expr_Tree_Builder :: Expr_Tree_Builder() : tree_() { }

Expr_Tree_Builder :: ~Expr_Tree_Builder()
{
    delete tree_;
} //end destructor

//I believe this is where input happens because there is no parameter for input
//
//construct a stack:
//-when the input token is an operand, push it to the stack
//-when the input token is an operator, pop two from the stack and make them the operator's children
//--push the operator onto the stack
//when you are done, the stack will only contain the root: construct the tree based on this root
virtual void Expr_Tree_Builder :: start_expression ()
{
    this->tree_ = new Expr_Tree ();

    std::stack <Expr_Node> s;
    //TODO
    //input stuff
    std::string input = "3 + 5 * 2 / 1";

    std::cout<<input<<std::endl;
    std::string postfix = infixToPostfix(input);
    std::cout<<postfix<<std::endl;

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
std::string Expr_Tree_Builder :: infixToPostfix(std::string infix)
{
    std :: string input = "", output = "";
    Stack <std::string> operators;
    Array<std::string > postfix;

    for (size_t i = 0; i < infix.size(); i++)
    {
        //move through the string character by character, splitting based on spaces
        if (infix[i] == ' ')
        {
            //numbers are immediately added
            if (isdigit(input))
            {
                output += input + " ";
            } //end if

            else if (input != ")")
            {
                if (input == "+" || input == "-")
                {
                    while (!operators.is_empty() && operators.top() != "(" && operators.top() != ")")
                    {
                        output += operators.top();
                        operators.pop();
                    } //end while
                    operators.push(input);
                } //end if

                //is this the correct precedence for modulus?
                else if (input == "*" || input == "/" || input == "%")
                {
                    while (!operators.is_empty() && operators.top() != "(" && operators.top() != ")" && operators.top() != "+" && operators.top() != "-")
                    {
                        output += operators.top();
                        operators.pop();
                    } //end while
                    operators.push(input);
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
        postfix.add(operators.top());
        operators.pop();
    } //end while

    return output;
} //end infixToPostfix

Expr_Tree * Expr_Tree_Builder :: get_expression (void)
{
    return this->tree_;
} //end getter

//builders which add each operation to the expression tree
virtual void Expr_Tree_Builder :: build_num(int n)
{
    Num_Node * toAdd = new Num_Node(n);
    tree_->add(toAdd);
} //end build_num

virtual void Expr_Tree_Builder :: build_add_operator()
{
    Add_Node * toAdd = new Add_Node();
    tree_->add(toAdd);
} //end build_add_operator

virtual void Expr_Tree_Builder :: build_sub_operator()
{
    Sub_Node * toAdd = new Sub_Node();
    tree_->add(toAdd);
} //end build_sub_operator

virtual void Expr_Tree_Builder :: build_mult_operator()
{
    Mult_Node * toAdd = new Mult_Node();
    tree_->add(toAdd);
} //end build_mult_operator

virtual void Expr_Tree_Builder ::build_div_operator()
{
    Div_Node * toAdd = new Div_Node();
    tree_->add(toAdd);
} //end build_div_operator

virtual void Expr_Tree_Builder :: build_mod_operator()
{
    Modulus_Node * toAdd = new Modulus_Node();
    tree_->add(toAdd);
} //end build_mod_operator

virtual void Expr_Tree_Builder :: build_open_paren()
{
    Open_Paren_Node * toAdd = new Open_Paren_Node();
    tree_->add(toAdd);
} //end build_open_parem

virtual void Expr_Tree_Builder ::build_close_paren()
{
    Close_Paren_Node * toAdd = new Close_Paren_Node();
    tree_->add(toAdd);
} //end build_close_paren