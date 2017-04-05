
//NOTE
//WHEN USING TEMPLATED CLASSES YOU CANNOT INCLUDE THE HEADER IN THE CPP AS YOU ARE ALREADY INCLUDING THE CPP IN THE HEADER
//IT'S JUST SHOWING AS A LOT OF ERRORS, DON'T WORRY ABOUT IT
//#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include "Array.h"
//default constructor

/*
template <typename T>
Array <T> ::Array (void)
        :cur_size_(0),
         max_size_(0),
         data_(new T[0])
{

} //end default constructor

//overloaded constructor
template <typename T>
Array <T>::Array (size_t length)
{
    data_ = new T[length]; //allocate memory on the heap

    for (size_t i = 0; i < length; i++)
    {
        data_[i] = 0;
    } //end for

    cur_size_ = length; //set the size of the new Array
    max_size_ = length;
} //end overloaded constructor

//overloaded constructor
template <typename T>
Array <T>::Array (size_t length, T fill)
{
    data_ = new T[length]; //create an Array of length

    //I probably could have just set data_ = new char[length] but that didn't seem legal given the assignment
    for (size_t i = 0; i < length; i++) //this can probably be done without a for loop
    {
        data_[i] = fill;
    } //end for

    cur_size_ = length; //set the size of the new Array
    max_size_ = length;
} //end overloaded constructor

//copy constructor
template <typename T>
Array <T>::Array (const Array & array)
{
    cur_size_ = array.size(); //sizes should equal the sizes on the passed array
    max_size_ = array.max_size();

    data_ = new T[cur_size_];

    for (size_t i = 0; i < cur_size_; i++)
    {
        data_[i] = array[i];
    } //end for
} //end copy constructor

//destructor
template <typename T>
Array <T>::~Array (void)
{
    delete [] data_; //delete the stuff we're pointing to
    data_ = 0; //set the pointer equal to null
} //end destructor

template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    resize(rhs.size()); //call the resize method, if the size isn't different nothing will happen anyway; if the size is different the array's size will change as necessary
    T * rhsData_ = rhs.data_; //so I don't have to dereference something already at an address

    for (size_t i = 0; i < cur_size_; i++)
    {
        *(data_ + i) = *(rhsData_ + i); //set the new location in the array equal to the equivalent location in rhs
    } //end for

    return *this; //I believe this is how to return a reference to self in c++
} //end = overload

template <typename T>
T & Array <T>::operator [] (size_t index)
{
    if (index > cur_size_) //check if index is in range
    {
        throw std :: out_of_range("Index out of bounds");
    } //end if

    else                       //if we're in range...
    {
        return *(data_ + index); //return the value at distance "index" from data_ pointer
    } //end else
} //end [] overload

template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
    if (index > cur_size_) //check if index is in range
    {
        throw std :: out_of_range("Index out of bounds");
    } //end if

    else
    {
        const T * myPoint = (data_ + index); //set a const pointer equal to the value we're getting, converting the item at that location to read only
        return * myPoint; //return the now const value
    } //end else} //end overloaded operator
} //end [] const overload

template <typename T>
T Array <T>::get (size_t index) const
{
    if (index >= cur_size_) //check if index is in range
    { //is this the correct way to throw exceptions in c++?
        throw std :: out_of_range("Index out of bounds");
    } //end if

    else                       //if we're in range...
    {
        return *(data_ + index); //return the value at distance "index" from data_ pointer
    } //end else
} //end get

template <typename T>
void Array <T>::set (size_t index, T value)
{
    if (index >= cur_size_) //check if we're in bounds
    {
        throw std :: out_of_range("Index out of bounds"); //throw exception if out of bounds
    } //end if

    else //otherwise, it is in bounds
    {
        *(data_ + index) = value;
    } //end else
} //end set

//return the index of the location of the first instance of value
//return -1 if instance is not found
template  <typename T>
int Array <T>::find (T value) const
{
    int rtn = -1; //returns -1 if nothing else is found

    for (size_t i = 0; i < cur_size_; i++) //move through all the elements
    {
        if (*(data_ + i) == value) //if the value is equal
        {
            rtn = i;
            break; //stop moving through the loop so the index can be returned
        } //end if
    } //end for

    return rtn;
} //end find

//same as original find method but start at given index
template <typename T>
int Array <T>::find (T val, size_t start) const
{
    int rtn = -1; //returns -1 if nothing else is found

    //I'm inexperienced with size_t; I'm wondering if this usage is incorrect
    for (size_t i = start; i < cur_size_; i++)
    {
        if (*(data_ + i) == val) //if the valeu is equal
        {
            rtn = i;
            break; //stop moving through the loop so the index can be returned
        } //end if
    } //end for

    return rtn;
} //end overloaded find

//overloaded equality operator
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
    bool rtn = true;

    if (cur_size_ != rhs.size()) //if the size is unequal, return false so we don't waste time
    {
        rtn = false;
    } //end if

    else //the size is equal, so check each individual item
    {
        T * rhsPoint = rhs.data_; //not sure how to dereference a pointer that I'm already dereferencing so I'm doing it in a separate line

        for (size_t i = 0; i < cur_size_; i++) //move through each item
        {
            if (*(data_ + i) != *(rhsPoint + i)) //if at any point a value is different, they are not equal
            {
                rtn = false;
                break; //not need to check the other items
            } //end if
        } //end for
    } //end else

    return rtn;
} //end overloaded ==

//overloaded inequality operator
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
    bool rtn = false;

    if (cur_size_ != rhs.cur_size_) //if the size is unequal, return true
    {
        rtn = true;
    } //end if

    else //otherwise, check every element in the array
    {
        T * rhsPoint = rhs.data_;

        for (size_t i = 0; i < cur_size_; i++)
        {
            if (*(data_ + i) != *(rhsPoint + i)) //if at any point a value is different, they are not equal
            {
                rtn = true;
                break; //no need to keep checkin
            } //end if
        } //end for
    } //end else

    return rtn;
} //end overloaded !=

template <typename T>
void Array <T>::fill (T value)
{
    T * temp = data_; //temporary pointer

    for (int i = 0; i < max_size_; i++) //for each item in the array...
    {
        *(data_ + i) = value; //set the value equal to new value
    } //end for
} //end fill

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if (new_size < cur_size_)
    {
        cur_size_ = new_size;
    } //end else if

    else if (new_size > cur_size_) //otherwise new_size is larger
    {
        for (size_t i = cur_size_; i < new_size; i++)
        {
            *(data_ + i) = 0; //set the new location equal to zero
        } //end for
        cur_size_ = new_size;
        max_size_ = new_size;
    } //end else if
} //end resize

//TODO temporary for getting this stuff to work
template <typename T>
size_t Array <T>::size () const
{
    return cur_size_;
}

template <typename T>
size_t Array <T>::max_size() const
{
    return max_size_;
}

 */