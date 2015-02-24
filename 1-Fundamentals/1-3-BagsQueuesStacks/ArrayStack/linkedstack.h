/*
    LinkedStack in C++ template
    This generic Stack implementation is based on a linked-list data structure.
    It can be used to create stacks containing any type of data.

    This use of linked lists achieves our optimum design goals:
    1. It can be used for any type of data;
    2. The space required is always proportional to the size of the collection.
    3. The time per operation is always independent of the size of the collection.

    This implementation is a prototype for many algorithm implementations that we consider.


*/


#ifndef LINKSTACK_H
#define LINKSTACK_H

//!!!1 Smart pointer is in "memory" header file
#include <memory>

template<typename T>
//!!!2 Camel-Case
class LinkedStack{
private:
    // Nested class to define nodes
    //!!!3 Default class scope is private
    //!!!3 And only syntactically nested, implementation hidden from client
    class Node{
        public:
            T item;
            std::shared_ptr<Node> next;
            // Constructor
            Node() = default;
            Node(T i, std::shared_ptr<Node> n): item(i), next(n){ }
    };
    std::shared_ptr<Node> first;
    std::size_t num;

public:
    // Default constructor
    LinkedStack():first(nullptr), num(0){ }
    bool isEmpty() const {
        return num == 0;
    }
    std::size_t size() const {
        return num;
    }
    // Add item to top of stack
    //!!!4 Use const and reference& whenever possible
    void push(const T &item){
        std::shared_ptr<Node> oldfirst(first);
        first = std::make_shared<Node>(item, oldfirst);
        num++;
    }
    // Remove item from top of stack
    T pop(){
        if(first == nullptr)throw(first);
        T item = first->item;
        first = first->next;
        num--;
        return item;
    }
};

#endif // LINKSTACK_H
