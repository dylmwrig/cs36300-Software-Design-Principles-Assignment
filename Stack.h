#ifndef CALCULATOR_STACK_H
#define CALCULATOR_STACK_H

#include <exception>
#include "Array.h"

template <typename T>
class Stack
{

public:
    /// Type definition of the type.
//    typedef T type;

    class empty_exception : public std::exception
    {
    public:
        /// Default constructor.
        empty_exception (void)
                : std::exception () {
        }
    }; //end exception

    /// Default constructor.
    Stack (void)
            :array_() { }

    /// Copy constructor.
    Stack (const Stack & s)
            :array_(s.array_) { }

    /// Destructor.
    ~Stack (void) { }

    const Stack & operator = (const Stack & rhs)
    {
        if (array_ != rhs.array_)
        {
            array_ = rhs.array_;
        } //end if

        return *this;
    } //end = overload

     void push (T element)
     {
         array_.resize(array_.size() + 1);
         array_.set(array_.size() - 1, element);
     } //end push

     void pop (void)
     {
         array_.resize(array_.size() - 1);
     } //end pop

     T top (void) const;

     bool is_empty (void) const;

    size_t size (void) const;

    /// Remove all elements from the stack.
    /// can't say I'm terrible confident about this method
    void clear (void)
    {
        T * data = &array_[0];

        delete[] data;
        data = new T();
        T * dataLoc = &array_[0]; //use a pointer due to lvalue vs rvalue issues caused otherwise
        dataLoc = data;
        array_.resize(0);
    } //end clear

private:
    // add member variable here
    Array <T> array_;

}; //end Stack

#include "Stack.inl"

// include the source file since template class
// THIS MUST BE AT THE END
// including implementation in header per nyalia's suggestion+
//#include "Stack.cpp"

#endif //CALCULATOR_STACK_H
