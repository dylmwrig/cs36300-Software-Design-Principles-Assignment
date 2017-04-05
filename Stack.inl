//
// size
// return number of elements in stack
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return array_.size();
} //end size

//
// top
// return the top element on the stack. throw is_empty if empty
template <typename T>
inline
T Stack <T>::top (void) const
{
    return array_.get(array_.size() - 1);
} //end top

//
// is_empty
// test if the stack is empty
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    if (array_.size() == 0)
    {
        return true;
    } //end if

    else
    {
        return false;
    } //end else
} //end is_empty