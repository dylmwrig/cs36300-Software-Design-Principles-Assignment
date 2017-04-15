#include <sstream>
#include "Calculator.h"

Calculator :: Calculator()
        : builder_() { }

Calculator :: ~Calculator() { }

bool Calculator :: parse_expr (const std::string & infix)
{
    std::istringstream input (infix); // create a input stream parser
    std::string token;
// current token in string/stream
    b.start_expression ();
// start a new expression
    while (!input.eof ())
    {
        input >> token;
        if (token == "+")
        {
            this->builder_.build_add_operator ();
        } //end if

        else if (token == "-")
        {
            this->builder_.build_sub_operator ();
        } //end else if

        else if (token == "*")
        {
            this->builder_.build_mult_operator ();
        } //end else if

        else if (token == "/")
        {
            this->builder_.build_div_operator();
        } //end else if

        else if (token == "%")
        {
            this->builder_.build_mod_operator();
        } //end else if
    } //end while
    return true;
} //end parse_expr
