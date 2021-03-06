#ifndef CALCULATOR2_EXPR_NODE_VISITOR_H
#define CALCULATOR2_EXPR_NODE_VISITOR_H

class Add_Node;
class Sub_Node;
class Num_Node;
class Mult_Node;
class Div_Node;
class Modulus_Node;
class Paren_Content_Node;

//abstract class for each concrete visitor to inherit from
//each inheriting class should just implement each of these method
class Expr_Node_Visitor
{
public:
    Expr_Node_Visitor(void);

    virtual ~Expr_Node_Visitor(void);

    //methods to visit each type of node
    virtual void Visit_Add_Node (const Add_Node & node) = 0;
    virtual void Visit_Sub_Node (const Sub_Node & node) = 0;
    virtual void Visit_Mult_Node (const Mult_Node & node) = 0;
    virtual void Visit_Div_Node (const Div_Node & node) = 0;
    virtual void Visit_Mod_Node (const Modulus_Node & node) = 0;
    virtual void Visit_Num_Node (const Num_Node & node) = 0;
    virtual void Visit_Paren_Node (const Paren_Content_Node & node) = 0;
}; //end Expr_Node_Visitor

#endif //CALCULATOR2_EXPR_NODE_VISITOR_H