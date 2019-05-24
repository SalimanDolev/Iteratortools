#pragma once
#include "iostream"
namespace itertools{

// powerset class
template <typename T>
class powerset{

private:
T group;

public:
// constructor
powerset(T a) : group(a){}

// iterator class
template <typename Z>
class iterator{
    Z start;

public:
// iterator constructor
iterator(Z a) : start(a){}

// iterator operators
Z& operator*(){
    return start;
}

iterator& operator++(){
    start++;
    return *this;
}

iterator &operator++(int){
    iterator temp = *this;
    start++;
    return temp;
}
        
bool operator==(const iterator &rhs) const{
        return true;
}

bool operator!=(const iterator &rhs) const{
        return false;
}

}; // end of iterator class

// iterator functions
auto begin()const{
    return group.begin();
}
auto end()const{
    return group.end();
}

}; // end of powerset class
} // end of namespace itertools