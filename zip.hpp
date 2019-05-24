#pragma once
#include "iostream"

namespace itertools{
// zip class
template <typename T, typename Z>
class zip{

private:
T first; // first container
Z second; // second container

public:    
//zip constructor
zip(T a, Z b) : first(a), second(b) {}


template <typename K, typename L>
class iterator{
K stPointer; // first container iterator
L ndPointer; // second container iterator

public:
//iterator constructor
iterator(K firstType, L secondType) : stPointer(firstType),ndPointer(secondType) {}
}; // end of iterator class

auto begin()const{
        return first.begin();
}

auto end()const{
        return first.end();
}
};//end of zip class
}// end of namespace itertools