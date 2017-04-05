#include "Num_Node.h"

Num_Node :: Num_Node (int n)
        :n_ (n){ }


int Num_Node :: getPrecedence()
{
    return precedence_;
} //end getPrecedence

bool Num_Node :: execute (void)
{
    s_.push (this->n_);
    //std::cout<<"new top of stack and size: " << s_.top() << " " << s_.size()<<std::endl;
    return true;
} //end execute