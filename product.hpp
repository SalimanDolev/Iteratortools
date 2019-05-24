#pragma once
#include "iostream"
namespace itertools{
    
template <typename T, typename Z>
class product{

private:
T first; // first container
Z second; // second container

public:
// product constructor
product(T a, Z b) : first(a), second(b) {}

// iterator class    
template <typename K, typename L>
class iterator{
K stPointer;
L ndPointer;

public:
//iterator constructor
iterator(K firstType, L secondType) : stPointer(firstType), ndPointer(secondType) {}

// iterator operators
K& operator*(){
    return stPointer;
}
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
}; // end of iterator class

// iteraor functions
auto begin()const{
    return first.begin();
}
auto end()const{
    return first.begin();
}
};// end of product class
}// end of namespace product