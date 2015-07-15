/** LinkedBag in C++ template
    ALGORITHM_1.4 -- linked list bag, with the support of generics and iteration
**/

#ifndef LINKEDBAG_H
#define LINKEDBAG_H

#include <memory>
             
template<typename T>
class LinkedBag {
    private:
        // Nested class -- node of linkedbag
        class Node {
            public:
                T item;
                std::shared_ptr<Node> next;
                
                Node() = default;
                Node(T i, std::shared_ptr<Node> n): item(i), next(n) {};
        };
        std::shared_ptr<Node> first;         // first node in list
        std::size_t num;
        // Nested class -- iterator of linkedbag
        class BagIter{
            private:
                std::shared_ptr<Node> iter;
            public:   
                BagIter() = default;
                BagIter(std::shared_ptr<Node> ptr): iter(ptr) {};  
                     
                bool operator!=(const BagIter &other) const{
                    return iter != other.iter;
                };
                bool operator==(const BagIter &other) const{
                    return iter == other.iter;
                };
                //! Return a reference should be declared as const
                T& operator*(){
                    return iter->item;
                };
                //! Return a reference should be declared as const
                BagIter& operator++(){
                    iter = iter->next;
                    return *this;
                };
                //! Do not try to fix this by returning a reference to the clone, cause it will crash your code for clone is a local variable.
                BagIter operator++(int) const{
                    iterator clone(*this);
                    iter = iter->next;
                    return clone;
                };
        };      
        typedef BagIter iterator;
        typedef std::ptrdiff_t difference_type;
        typedef std::size_t size_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        
    public:
        LinkedBag(): first(nullptr), num(0) {};
        bool isEmpty() const {
            return 0 == num;
        };
        std::size_t size() const {
            return num;
        };
        // same as push() in Stack
        void add(const T &item){
            std::shared_ptr<Node> oldfirst = first;
            first = std::make_shared<Node>(item, oldfirst);
            ++num;
        };
        
        // some function about iteration
        //! It is not a const iterator
        iterator begin() {
            return iterator(first);
        };
        iterator end() {
            return iterator(nullptr);
        };
        
};

#endif // LINKEDBAG_H
