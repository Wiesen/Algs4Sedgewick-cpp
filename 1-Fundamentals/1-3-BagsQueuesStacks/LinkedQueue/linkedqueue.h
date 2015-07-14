/** LinkedQueue in C++ template
    ALGORITHM_1.3--FIFO linked list queue. It achieves our optimum design goals:
    1. It can be used for any type of data;
    2. The space required is proportional to the number of items in the collection;
    3. The time required per operation is always independent of the size of the collection.
**/

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <memory>                   // Where smart pointer is included

template<typename T>
class LinkedQueue{
	private:
		class Node{                 // nested class to define nodes
			public:
				T item;
				std::shared_ptr<Node> next;
		        
		        Node() = default;
		        Node(T i, std::shared_ptr<Node> n): item(i), next(n) {};
		};
		std::shared_ptr<Node> first;// link to least recently added node
		std::shared_ptr<Node> last; // link to most recently added node
		std::size_t num;            // number of items on the queue
		
	public:
	    LinkedQueue():first(nullptr), last(nullptr), num(0) {};
	    
	    bool isEmpty() const {      // Return whether the queue is empty
	        return 0 == num;
	    };
	    std::size_t size() const {  // Return the size of queue
	        return num;
	    };
	    
	    /**
         * @brief: Add item to the end of the list
         * @param: T item
         */
	    void enqueue(const T &item) {       //! Use const and reference whenever possible
	        std::shared_ptr<Node> oldlast = last;
	        last = std::make_shared<Node>(item, nullptr);
	        if(isEmpty())first = last;
	        else oldlast->next = last;
	        ++num;
	    };
	    /**
         * @brief: Remove item from the beginning of the list
         * @return: The item which is removed
         */
	    T dequeue(){
	        if(isEmpty())throw(first);
	        T ret = first->item;
	        first = first->next;
	        --num;
	        return ret;
	    };
//! error: expected ‘;’ after class definition 
};

#endif  // LINKEDQUEUE_H
