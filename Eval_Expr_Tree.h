#ifndef CALCULATOR2_EXPR_NODE_VISITOR_H
#define CALCULATOR2_EXPR_NODE_VISITOR_H


#include "Add_Node.h"
#include "Sub_Node.h"
#include "Num_Node.h"
#include "Mult_Node.h"
#include "Div_Node.h"
#include "Modulus_Node.h"

//#include "Expr_Node_Visitor.h"

/*
class Add_Node;
class Sub_Node;
class Num_Node;
class Mult_Node;
class Div_Node;
class Modulus_Node;
//class Expr_Node_Visitor;
*/

class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:
    Eval_Expr_Tree (void);
    virtual ~Eval_Expr_Tree (void);
    // Methods for visiting concrete nodes
    virtual void Visit_Add_Node (const Add_Node & node); // visit left node, visit right node, then perform addition
    virtual void Visit_Sub_Node (const Sub_Node & node);
    virtual void Visit_Mult_Node (const Mult_Node & node);
    virtual void Visit_Div_Node (const Div_Node & node);
    virtual void Visit_Mod_Node (const Modulus_Node & node);
    virtual void Visit_Num_Node (const Num_Node & node);

    int result (void) const;

private:
    int result_; //cumulative state used for calculating the result
}; //end Eval_Expr_Tree

#endif //CALCULATOR2_EXPR_NODE_VISITOR_H
