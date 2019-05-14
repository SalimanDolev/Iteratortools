#pragma once
#include "iostream"
namespace itertools
{
template <typename T>
class powerset
{
    private:
    T group;
    public:
    powerset(T a) : group(a){}

    
    template <typename Z>
    class iterator
    {
        Z start;

    public:
        iterator(Z a) : start(a){}
        
        
        Z& operator*()
        {
            return start;
        }

        iterator& operator++()
        {
            start++;
            return *this;
        }

        iterator &operator++(int)
        {
            iterator temp = *this;
            start++;
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
    
    auto begin()
    {
        return group.begin();
    }

    auto end()
    {
        return group.end();
    }
};
}