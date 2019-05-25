#pragma once
#include "iostream"
namespace itertools{
bool Help  = false;

    template <typename T, typename Z>
    class product{

private:
T first; // first container
Z second; // second container

public:
// product constructor
product(T a, Z b) : first(a), second(b) { 
    Help = false;
if(!(second.begin()!= second.end())){
    Help = true;
}
}

// iterator class    
template <typename K, typename L>
class iterator{
K stPointer;
L ndPointer;
L pos;
bool move;

public:
//iterator constructor
iterator(K firstType, L secondType) : stPointer(firstType), ndPointer(secondType),pos(ndPointer),move(false) {}

// iterator operators
auto operator*()const{
    return std::pair<decltype(*stPointer),decltype(*ndPointer)> (*stPointer,*ndPointer);
}
iterator <K,L>& operator++(){
    if(!move){
        ++ndPointer;
    }
    return *this;
}

 bool operator!=(iterator it){
                if((stPointer != it.stPointer) && !(ndPointer != it.ndPointer)){
                move=true;
                }
                if(move){
                move=false;
                ndPointer = pos;
                ++stPointer;
                }
                return (stPointer != it.stPointer && !Help);

            }
}; // end of iterator class

// iteraor functions
auto begin()const{
    return iterator<decltype(first.begin()),decltype(second.begin())>(first.begin(), second.begin());
}
auto end()const{
    return iterator<decltype(first.end()),decltype(second.end())>(first.end(), second.end());
}
};// end of product class
}// end of namespace product