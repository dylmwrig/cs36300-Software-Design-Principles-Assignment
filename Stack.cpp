/*

#include "Stack.h"
//
// Stack
// default constructor
// keep in mind that the stack is LIFO
template <typename T>
Stack <T>::Stack (void) : array_()
{

} //end constructor

//
// Stack
// copy constructor
template <typename T>
Stack <T>::Stack (const Stack & stack)
{
  array_ = stack.array_;
} //end copy constructor

//
// ~Stack
// destructor
template <typename T>
Stack <T>::~Stack (void)
{

}

//
// push
// insert a new value at the end of the stack
template <typename T>
void Stack <T>::push (T element)
{
  array_.resize(array_.size() + 1);
  array_.set(array_.size() - 1, element);
} //end push

//
// pop
// remove the top element
template <typename T>
void Stack <T>::pop (void)
{
  array_.resize(array_.size() - 1);
} //end pop


//check for self assignment (if the array members are equal)
//if the assigned stack is different, set this array equal to that one
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
  if (array_ != rhs.array_)
  {
    array_ = rhs.array_;
  } //end if

  return *this;
} //end = overload


//delete the data of the array member
//set a pointer to the first value (which should represent data_ pointer in the origin array)
//delete the pointer and set the location at index 0 equal to a new T
//set the size equal to zero
template <typename T>
void Stack <T>::clear (void)
{
  T * data = &array_[0];

  delete[] data;
  data = new T();
  T * dataLoc = &array_[0]; //use a pointer due to lvalue vs rvalue issues caused otherwise
  dataLoc = data;
  array_.resize(0);
} //end clear

 */