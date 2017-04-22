#ifndef CALCULATOR2_EXPR_TREE_H
#define CALCULATOR2_EXPR_TREE_H


#include "Expr_Node.h"

//tree which the expression will live on
//needs methods to add and access the tree
class Expr_Tree
{
public:
    Expr_Tree(void);
    virtual ~Expr_Tree(void);
    void add (Expr_Node * toAdd);

private:
    Expr_Node * root;
}; //end Expr_Tree

#endif //CALCULATOR2_EXPR_TREE_H