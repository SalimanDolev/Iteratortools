#pragma once
#include "iostream"

namespace itertools
{
template <typename T, typename Z>
class zip
{
    public:
    T first;
    Z second;
    
    zip(T a, Z b) : first(a), second(b) {}
    
    template <typename K, typename L>
    class iterator
    {
        K stPointer;
        L ndPointer;

    public:
        iterator(K firstType, L secondType) : stPointer(firstType),ndPointer(secondType) {}
    };

    auto begin()
    {
        return first.begin();
    }

    auto end()
    {
        return first.end();
    }
};
}