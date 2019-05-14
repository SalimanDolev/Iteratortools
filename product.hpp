#include "iostream"


namespace itertools {

    template <typename Template1, typename Template2>
    class product {

    private: 
        Template1 it1; // first variable
        Template2 it2; // second variable
    //constructor
    public:
        product(Template1 start, Template2 end) :  it1(start), it2(end) {}

    // begin and end iterator functions
    auto begin(){
        return  iterator<decltype(it1.begin()),decltype(it2.begin())>(it1.begin(), it2.begin()); }  // iteratable object

    auto end() {
        return iterator<decltype(it1.end()),decltype(it2.end())>(it1.end(), it2.end()); }  // iteratable object
    //iterator class
    template <typename C1, typename C2>
        class iterator {

        private:
            C1 it1;
            C2 it2;
            C2 pos;

        public:
        // iterator constructor
            iterator(C1 itA , C2 itB): it1(itA) , it2(itB) , pos(it2) {}
        //operator ++ for iterator
           iterator<C1,C2>& operator++() {
               ++it2;
               return *this;

            }
        //operator > for iterator
            std::pair<decltype(*it1),decltype(*it2)> operator*() const {

             return  std::pair<decltype(*it1),decltype(*it2)> (*it1 , *it2);
            }
        // operator != for iterator
            bool operator!=(iterator<C1,C2>  it){
                if((it1 != it.it1) && !(it2 != it.it2)){
                    it2 = pos;
                    ++it1;
                }
                return (it1 != it.it1);
            }
        };
    };
}