#pragma once
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>

namespace itertools {
template <typename T1, typename T2>

class zip {

private:
T1 iter1; // first tool
T2 iter2; // second tool

public:
zip(T1 first, T2 last) :  iter1(first), iter2(last) {
}
// iterator begin and end functions
auto begin(){
        return iterator<decltype(iter1.begin()),decltype(iter2.begin())>(iter1.begin(), iter2.begin());
}                                                                                                
auto end() {
        return iterator<decltype(iter1.end()),decltype(iter2.end())>(iter1.end(), iter2.end());
}                                                                                      
// iterator class
template <typename I1, typename I2>
class iterator {

private:
I1 iter1;             // iterator A
I2 iter2;             // iterator B

public:
iterator(I1 _iter1, I2 _iter2) : iter1(_iter1), iter2(_iter2)  {
}

iterator<I1,I2>& operator++() {
        ++iter1;
        ++iter2;
        return *this;

}


std::pair<decltype(*iter1),decltype(*iter2)> operator*() const {

        return std::pair<decltype(*iter1),decltype(*iter2)> (*iter1, *iter2);
}

bool operator!=(iterator<I1,I2>  it){
        return (iter1 != it.iter1) && (iter2 != it.iter2);

}
};//iterator       
};//zip class
template <typename L,typename M>
std::ostream &operator<<(std::ostream &os, const std::pair<L,M> &c){
        os << c.first << ',' << c.second;

        return os;
}//operator <<
}//namespace itertools