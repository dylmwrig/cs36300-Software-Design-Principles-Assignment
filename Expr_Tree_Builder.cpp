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
virtual void Expr_Tree_Builder :: start_expression ()
{
    this->tree_ = new Expr_Tree ();

    Stack <Expr_Node> nodes;
    //TODO
    //input stuff
    std::string input = "3 + 5 * 2 / 1";

    //taken from driver
    /*
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