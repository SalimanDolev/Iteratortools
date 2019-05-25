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
bool move;

public:
//iterator constructor
iterator(K firstType, L secondType) : stPointer(firstType), ndPointer(secondType) {}

// iterator operators
auto operator*(){
    return std::pair<decltype(*stPointer),decltype(*ndPointer> (*stPointer,*ndPointer);
}
iterator <K,L>& operator++(){
    if(!move){
        ++ndPointer;
    }
    return *this;
}

iterator<K,L>& operator++() {
            if(move)
               ++ndPointer;
               return *this;

            }

 bool operator!=(iterator const  it){
                if((stPointer != it.stPointer) && !(ndPointer != it.ndPointer)){
                  move=true;
                }
                if(move){

                move=false;
                    ++stPointer;
                }
                return (stPointer != it.stPointer);

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