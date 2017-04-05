#ifndef CALCULATOR_ARRAY_H
#define CALCULATOR_ARRAY_H

#include <cstddef> //size_t definition
#include <iostream>

template <typename T>
class Array
{
    //typedef T type;

public:
    //template <typename T>
    Array(void)
            :cur_size_(0),
            max_size_(0),
            data_(new T[0]){ } //end constructor

    Array(const Array<T> & arr)
            :cur_size_(arr.cur_size_),
             max_size_(arr.max_size_),
             data_(arr.data_){ } //end copy constructor

    Array(size_t length)
            :cur_size_(length),
             max_size_(length),
             data_(new T[length]) { } //end overloaded constructor

    Array(size_t length, T fill)
            :cur_size_(length),
             max_size_(length),
             data_(new T[length])
    {
        for (size_t i = 0; i < length; i++)
        {
            data_[i] = fill;
        } //end for
    } //end overloaded constructor

    ~Array(void)
    {
        delete [] data_;
    } //end destructor

    void fill (T element)
    {
        for (int i = 0; i < max_size_; i++) //for each item in the array...
        {
            *(data_ + i) = element; //set the value equal to new value
        } //end for
    } //end fill

    void set (size_t index, T value)
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

    T get (size_t index) const
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

    //adding my own "add" function to make the array a little easier to deal with
    //should feel more like a vector after this
    void add (T element)
    {
        resize(cur_size_ + 1);
        data_[cur_size_ - 1] = element;
    } //end add

    int find (T element) const
    {
        int rtn = -1; //returns -1 if nothing else is found

        for (size_t i = 0; i < cur_size_; i++) //move through all the elements
        {
            if (*(data_ + i) == element) //if the value is equal
            {
                rtn = i;
                break; //stop moving through the loop so the index can be returned
            } //end if
        } //end for

        return rtn;
    } //end find

    int find (T element, size_t start) const
    {
        const int rtn = find(element);

        return rtn;
    } //end const find

    //TODO
    //because I'm not deleting the data pointer before changing the value so could this either result
    //in a memory leak or possibly having previously existing data still reachable but unchanged?
    //
    //so if an array of size 6 is resized to an array of size 3
    //would this leave elements 4-6?
    const Array & operator = (const Array & rhs)
    {
        cur_size_ = rhs.cur_size_;
        max_size_ = rhs.max_size_;
        data_ = rhs.data_; //so I don't have to dereference something already at an address

        //for the reason for the comment above the overloaded operator definition I left the
        //commented out code from the original version
        /*
        for (size_t i = 0; i < cur_size_; i++)
        {
            *(data_ + i) = *(rhsData_ + i); //set the new location in the array equal to the equivalent location in rhs
        } //end for
        */

        return *this; //I believe this is how to return a reference to self in c++
    } //end overloaded operator

    T & operator [] (size_t index)
    {
        if (index > cur_size_) //check if index is in range
        {
            throw std :: out_of_range("Index out of bounds");
        } //end if

        else                       //if we're in range...
        {
            return *(data_ + index); //return the value at distance "index" from data_ pointer
        } //end else
    } //end overloaded operator

    const T & operator [] (size_t index) const
    {
        T rtn = get(index);
        return rtn;
    } //end overloaded operator

    bool operator == (const Array & rhs) const
    {
        if (cur_size_ != rhs.cur_size_) //if the size is unequal, return false so we don't waste time
        {
            return false;
        } //end if

        else //the size is equal, so check each individual item
        {
            T * rhsPoint = rhs.data_;

            for (size_t i = 0; i < cur_size_; i++)
            {
                if (*(data_ + i) != *(rhsPoint + i)) //if at any point a value is different, they are not equal
                {
                    return false;
                } //end if
            } //end for
        } //end else

        return true;
    } //end overloaded ==

    bool operator != (const Array & rhs) const
    {
        if (cur_size_ != rhs.cur_size_) //if the size is unequal, return true
        {
            return true;
        } //end if

        else //otherwise, check every element in the array
        {
            T * rhsPoint = rhs.data_;

            for (size_t i = 0; i < cur_size_; i++)
            {
                if (*(data_ + i) != *(rhsPoint + i)) //if at any point a value is different, they are not equal
                {
                    return true;
                } //end if
            } //end for
        } //end else

        return false;
    } //end overloaded !=

    //methods unique to generic array object
    void resize (size_t new_size)
    {
        if (new_size < cur_size_)
        {
            cur_size_ = new_size;
        } //end else if

        else if (new_size > cur_size_) //otherwise new_size is larger
        {
            T * tempData = new T[new_size];

            for (size_t i = 0; i < cur_size_; i++)
            {
                tempData[i] = data_[i];
            } //end for

            data_ = tempData;
            cur_size_ = new_size;
            max_size_ = new_size;
        } //end else if
} //end resize
    //void shrink(void);

    size_t size (void) const {return cur_size_ ;}
    size_t max_size (void) const {return max_size_;}

private:
    int cur_size_;
    int max_size_;
    T * data_;
}; //end Array class

//going to try including implementation in header due to weird errors and nyalia's suggestion
//#include "Array.cpp"

#endif //CALCULATOR_ARRAY_H