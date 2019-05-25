#pragma once
#include "iostream"
namespace itertools {

template <typename T>
class range {
// private variable for range class    
private:
    T start; // first variable of the range
    T stop;  // last variable of the range   

public:
//range constructor
range(T first, T last) : start(first),stop(last) {}
    
// iterator class    
class iterator{

T iter; // iterator veriable

public:
//iterator constructor
iterator(T index){
        iter = index;
}
// iterator operators
T operator*() const{
        return iter;
}

iterator& operator++(){
        iter++;
        return *this;
}
        
bool operator==(iterator const &rhs) const{
        return iter == rhs.iter;
}

bool operator!=(iterator const &rhs) const{
        return iter != rhs.iter;
}
};//end of iterator class

   // begin and end function for iterator     
/*iterator begin(){
return range<T>::iterator(start);
}    
iterator end(){
return range<T>::iterator(stop);
}*/

iterator begin() const{
return iterator(start);

}    
iterator end() const{
return iterator(stop);

}

};//end of range class
} // end of namespce itertools