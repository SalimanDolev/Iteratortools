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

iterator<K,L>& operator++() {
        ++stPointer;
        ++ndPointer;
        return *this;

}


std::pair<decltype(*stPointer),decltype(*ndPointer)> operator*() const {

        return std::pair<decltype(*stPointer),decltype(*ndPointer)> (*stPointer, *ndPointer);
}

bool operator!=(iterator<K,L>  it){
        return (stPointer != it.stPointer) && (ndPointer != it.ndPointer);
}

}; // end of iterator class

auto begin()const{
        return iterator<decltype(first.begin()),decltype(second.begin())>(first.begin(), second.begin());
}

auto end()const{
        return iterator<decltype(first.end()),decltype(second.end())>(first.end(), second.end());
}
};//end of zip class
template <typename T,typename E>
std::ostream &operator<<(std::ostream &os, const std::pair<T,E> &c){
        os << c.first << ',' << c.second;

        return os;
}

}// end of namespace itertools