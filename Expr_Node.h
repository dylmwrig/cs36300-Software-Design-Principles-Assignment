#ifndef CALCULATOR_EXPR_NODE_H
#define CALCULATOR_EXPR_NODE_H

class Expr_Node_Visitor;

//pure virtual class for each kind of command to inherit from
class Expr_Node
{
public:
    Expr_Node (void);
    virtual ~Expr_Node(void);

    virtual int evaluate (void) const = 0;
    virtual void accept (Expr_Node_Visitor & v) = 0; //used for traversal using visitor class
}; //end Expr_Node

#endif //CALCULATOR_EXPR_NODE_H