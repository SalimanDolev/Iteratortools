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
class iterator {

  K stPointer; // first container iterator
  L ndPointer; // second container iterator
  bool whoFirst;

public:
// iterator constructor
iterator(K firstType, L secondType) : stPointer(firstType),ndPointer(secondType) {}


// iterator operators

decltype(*stPointer) operator*() const {

        if(whoFirst)
                return *stPointer;
        else
                return *ndPointer;
}
iterator<K,L>& operator++() {
        if(whoFirst==true)
                ++stPointer;
        else
                ++ndPointer;
        return *this;
}

bool operator!=(const iterator <K,L> rhs){
        if(whoFirst && !(stPointer != rhs.stPointer)) {
                whoFirst = false;
        }
        if(whoFirst) {
                return stPointer != rhs.stPointer;
        }else{
                return ndPointer != rhs.ndPointer;
        }
}
        
};// end of iterator class
// iterator begin and end functions

auto begin() const{
return iterator<decltype(first.begin()),decltype(second.begin())>(first.begin(), second.begin());;
}

auto end()const{
return iterator<decltype(first.end()),decltype(second.end())>(first.end(), second.end());;
}

};// rnd of chain class
} // end of itertools namespace