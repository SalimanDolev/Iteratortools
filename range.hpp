#pragma once
#include <iterator>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iterator>
using namespace std;


namespace itertools{
template <typename T>
class range{
private:
T min; // present the minimum number
T max; // present the max number
public:
// constructor for integer range number
range(T a , T b){
   this->min = a;
    this->max = b;
}

class iterator {
private:
 T* it;
public:
iterator(T* it = nullptr) : it(it){
}

iterator& operator++() {
        (*it)++;
        return *this;
}


T& operator*() const {
        return *it;
}


const iterator operator++(int) {
        iterator temp = *this;
        it++;
        return temp;
}

bool operator!=(iterator itr) const {
        return *it != *itr.it;
}

bool operator==(iterator itr) const {
        return *it == *itr.it;
}
};

iterator begin()
{
        return iterator{&min};
}

iterator end()
{
        return iterator{&max};
}
};
}
