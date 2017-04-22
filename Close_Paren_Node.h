#ifndef CALCULATOR2_CLOSE_PAREN_NODE_H
#define CALCULATOR2_CLOSE_PAREN_NODE_H


#include "Binary_Expr_Node.h"

class Close_Paren_Node : public Binary_Expr_Node
{
public:
    Close_Paren_Node(void);

    ~Close_Paren_Node(void);

    int evaluate () const;
    virtual void accept (Expr_Node_Visitor & v);
}; //end Close_Paren_Node

#endif //CALCULATOR2_CLOSE_PAREN_NODE_H