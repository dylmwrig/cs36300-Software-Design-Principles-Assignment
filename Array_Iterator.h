#ifndef CALCULATOR_ARRAY_ITERATOR_H
#define CALCULATOR_ARRAY_ITERATOR_H

#include "Array.h"

template <typename T>
class Array_Iterator
{
public:
    Array_Iterator (Array <T> & a)
            :a_ (a),
             curr_ (0) { }

    ~Array_Iterator (void) { }

    bool is_done (void)
    {
        return this->curr_ >= this->a_.size();
    } //end is_done

    bool advance (void)
    {
        ++ this->curr_;
        return true;
    } //end advance

    T & operator * (void)
    {
        return this->a_[this->curr_];
    } //end operator overload

    T * operator -> (void)
    {
        return &this->a_[this->curr_];
    } //end operator overload
private:
    Array <T> & a_;
    size_t curr_;
}; //end Array_Iterator

#endif //CALCULATOR_ARRAY_ITERATOR_H
