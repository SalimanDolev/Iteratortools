#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>

namespace itertools{

template <typename T1 , typename T2>
class chain{

private:
T1 first;
T2 last;

public:
//constructor of chain
chain(T1 t1 , T2 t2){   
this->first = t1;
this->last = t2;
}
// return the start of the chain
auto begin(){
     return iterator<decltype(first.begin()),decltype(last.begin())>(first.begin(), last.begin());
}
// return the end of the chain
auto end(){
    return iterator<decltype(first.end()),decltype(last.end())>(first.end(), last.end());
}

template <typename I1 , typename I2>
class iterator{
private:
I1 iter1;
I2 iter2;
bool isFirst;
public:
iterator (I1 it1,I2 it2){
    this->iter1 = it1;
    this->iter2 = it2;
    this->isFirst=true;
}
// returning the itertor pointer
decltype (*iter1) operator*() const{
    return *iter1;

}
// Adding the iterator one
iterator<I1,I2>& operator++() {
        if(isFirst==true)
                ++iter1;
        else
                ++iter2;
        return *this;
}
//adding the iterator some numbers
const iterator operator++(int) {

}
// cheking if the iterator are equals
bool operator==(iterator itr) const {
if (itr.iter1 == this->iter1 && itr.iter2== this->iter2)
    return true;

else
    return false;
}
//checking if the iterator is not equals
bool operator!=(iterator<I1,I2>  it){
        if(isFirst && !(iter1 != it.iter1)) {
                isFirst = false;
        }
        if(isFirst) {
                return iter1 != it.iter1;
        }else{
                return iter2 != it.iter2;
        }
}

};//iterator

};//chain

};//itertools
