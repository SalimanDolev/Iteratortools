#pragma once
#include "iostream"
namespace itertools
{
template <typename T>
class range 
{
    
private:
    T start;
    T stop;
public:
    range(T first, T last) : start(first),stop(last) {}

    class iterator
    {
        T Pointer;

    public:
        iterator(T index)
        {
            Pointer = index;
        }

        T& operator*()
        {
            return Pointer;
        }

        iterator& operator++()
        {
            Pointer++;
            return *this;
        }

        iterator &operator++(int)
        {
            iterator temp = *this;
            Pointer++;
            return temp;
        }
        
        bool operator==(const iterator &rhs) const
        {
            return true;
        }

        bool operator!=(const iterator &rhs) const
        {
            return false;
        }
    };

    iterator begin()
    {
        return range<T>::iterator(start);

    }

    iterator end()
    {
        return range<T>::iterator(stop);

    }

};
} 