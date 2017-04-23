#ifndef CALCULATOR2_EXPR_TREE_H
#define CALCULATOR2_EXPR_TREE_H

#include "Expr_Node.h"

//tree which the expression will live on
//needs methods to add and access the tree
class Expr_Tree
{
public:
    Expr_Tree(Expr_Node * root);
    virtual ~Expr_Tree(void);
    void accept(Expr_Node_Visitor & v);

private:
    Expr_Node * root_;
}; //end Expr_Tree

#endif //CALCULATOR2_EXPR_TREE_H