/**
    ArrayStack in C++ template
    ALGORITHM 1.1 almost (but not quite) achieves optimum performance goals for any collection implementation:
    1. Each operation should require time independent of the collection size.
    2. The space used should always be within a constant factor of the collection size.

    It resizes the array to keep the array size within a constant factor of the stack size,
    which is between 25% to 100%.
**/

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <memory>

template<typename T>
class ArrayStack{
private:
    //! Data member, it must be declared as pointer or add '*' separately
    T* elem;
    T* first_free;
    T* cap;
    //! Use class template allocator to allocate and construct
    std::allocator<T> alloc;
    //! utillities
    void check();
    void alloc_n_move(const std::size_t &newCap);
    void free();

public:
    ArrayStack(): elem(nullptr), first_free(nullptr), cap(nullptr) { }
    ~ArrayStack() { free(); }

    void push(const T &item);
    T pop();

    std::size_t size() const {
        return first_free - elem;
    }
    std::size_t capacity() const{
        return cap - elem;
    }
    bool isEmpty() const {
        return elem == nullptr;
    }
};

/**
 * @brief   Check the memory and reallocate if necessary, then push the new item on the top of stack
 * @param   T item
 */
template<typename T>
void ArrayStack<T>::push(const T &item){
    check();
    alloc.construct(first_free++, item);
}

/**
 * @brief   Pop out the item on the top of stack, then reallocate memory if necessary
 * @return  The item which is popped out
 */
template<typename T>
T ArrayStack<T>::pop(){
    if(elem == nullptr)throw(first_free);
    T item = *(--first_free);
    alloc.destroy(first_free);
    check();
    return item;
}

/**
 * @brief   Check the capacity of the stack
 *          if not enough, then reallocate: Double the capacity
 *          else if too large , then resize: halve the capacity
 *          which using std::move move the original data to the newly allocated memory.
 */
template<typename T>
void ArrayStack<T>::check(){
    // Reallocate - not enough
    if(first_free == cap){
        std::size_t newCap = size() ? size() * 2 : 1;
        alloc_n_move(newCap);
    }
    // Resize - too large
    else if(size() > 0 && size() == capacity() / 4){
        // Method 1: reallocate memory and move the items
        //alloc_n_move(capacity() / 2);
        // Method 2: simply deallocate the redundant memory, which is more efficient
        alloc.deallocate(elem + capacity() / 2, capacity() / 2);
        cap = elem + capacity() / 2;
    }
}

/**
 * @brief   allocate memory for specified number of elements
 * @param   n
 */
template<typename T>
void ArrayStack<T>::alloc_n_move(const std::size_t &newCap){
    T* newSpace = alloc.allocate(newCap);
    T* dest = newSpace;
    T* src = elem;
    for(std::size_t i = 0; i != size(); ++i){
        alloc.construct(dest++, std::move(*src++));
    }
    free();
    // Update data member
    elem = newSpace;
    first_free = dest;
    cap = elem + newCap;
}

/**
 * @brief   Destroy the elements and deallocate the space previously allocated.
 */
template<typename T>
void ArrayStack<T>::free(){
    if(elem != nullptr){
        for(auto p = elem; p != first_free; p++)
            alloc.destroy(p);
        alloc.deallocate(elem, capacity());
    }
}

#endif // ARRAYSTACK_H
