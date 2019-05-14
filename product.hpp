#pragma once
#include "iostream"
namespace itertools
{
template <typename T, typename Z>
class product
{
    public:
    T first;
    Z second;

    product(T a, Z b) : first(a), second(b) {}
    
    template <typename K, typename L>
    class iterator
    {
       K stPointer;
        L ndPointer;

    public:
        iterator(K firstType, L secondType) : stPointer(firstType), ndPointer(secondType) {}
        
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

public: 

    auto begin()
    {
        return first.begin();
    }

    auto end()
    {
        return first.begin();
    }
};
}