#pragma once
#include "iostream"

namespace itertools{

template <typename T, typename Z>
class chain{
    
public:
T first; // first container
Z second; // second container

// chain constructor    
chain(T a, Z b) : first(a),second(b) {}

// iterator class
template <typename K, typename L>
class iterator
{
  K stPointer; // first container iterator
  L ndPointer; // second container iterator

public:
// iterator constructor
iterator(K firstType, L secondType) : stPointer(firstType),ndPointer(secondType) {}
        
K& operator*(){
        return stPointer;
}
// iterator operators
iterator& operator++(){
        stPointer++;
        return *this;
}

iterator &operator++(int){
        iterator temp = *this;
        stPointer++;
        return temp;
}
        
bool operator==(const iterator &rhs) const{
        return true;
}

bool operator!=(const iterator &rhs) const{
        return false;
}
        
};// end of iterator class
// iterator begin and end functions

auto begin() const{
return first.begin();
}

auto end()const{
       return first.end();
}

};// rnd of chain class
} // end of itertools namespace