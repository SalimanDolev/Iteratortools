#pragma once
#include "iostream"

namespace itertools
{
template <typename T, typename Z>
class chain
{
    
public:
    T first;
    Z second;
    
    chain(T a, Z b) : first(a),second(b) {}

    template <typename K, typename L>
    class iterator
    {
        K stPointer;
        L ndPointer;

    public:
    
        iterator(K firstType, L secondType) : stPointer(firstType),ndPointer(secondType) {}
        
         K& operator*()
        {
            return stPointer;
        }

        iterator& operator++()
        {
            stPointer++;
            return *this;
        }

        iterator &operator++(int)
        {
            iterator temp = *this;
            stPointer++;
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
        return first.begin();
        //return chain::iterator<decltype(first.begin()),decltype(second.begin())>(first.begin(),second.begin()); // add operators

    }

    auto end()
    {
       return first.end();
       //return chain::iterator<decltype(first.end()),decltype(second.end())>(first.end(),second.end()); // add operators
    }

};
}