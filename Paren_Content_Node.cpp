#include "Paren_Content_Node.h"
#include "Expr_Node_Visitor.h"
#include "Calculator.h"

Paren_Content_Node :: Paren_Content_Node(std::string subExpression)
                    :n_(0)
{
    Calculator calculator;
    n_ = calculator.calculate(subExpression);
} //end constructor

Paren_Content_Node :: ~Paren_Content_Node() { }

int Paren_Content_Node :: evaluate () const
{
    return n_;
} //end evaluate

void Paren_Content_Node :: accept(Expr_Node_Visitor &v)
{
    v.Visit_Paren_Node(*this);
} //end accept