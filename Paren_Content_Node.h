#ifndef CALCULATOR2_PAREN_CONTENT_NODE_H
#define CALCULATOR2_PAREN_CONTENT_NODE_H

#include <iostream>
#include "Binary_Expr_Node.h"

//when I encounter a parenthesis, I just send the contents of that parentheses expression into a new calculator
//this node will just hold the results of those calculations
class Paren_Content_Node : public Expr_Node
{
public:
    //get the number value of this node by passing the sub expression into a calculator
    Paren_Content_Node(std::string subExpression);

    ~Paren_Content_Node(void);

    int evaluate () const;
    virtual void accept (Expr_Node_Visitor & v);

private:
    int n_;
}; //end Paren_Content_Node

#endif //CALCULATOR2_PAREN_CONTENT_NODE_H