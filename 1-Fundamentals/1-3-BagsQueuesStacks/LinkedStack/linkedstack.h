//!!!1 Smart pointer is in "memory" header
#include <memory>

template<typename T>
//!!!4 Camel-Case
class LinkedStack{
private:
    //!!!2 Default class scope is private
    //!!!2 And only syntactically nested, implementation hidden
    class Node{
        public:
            T item;
            std::shared_ptr<Node> next;

            Node() = default;
            Node(T i, std::shared_ptr<Node> n): item(i), next(n){ }
    };
    std::shared_ptr<Node> first;
    std::size_t num;

public:
    LinkedStack():first(nullptr), num(0){ }
    bool isEmpty() const {
        return num == 0;
    }
    std::size_t size() const {
        return num;
    }
    //!!!3 Use const and reference& whenever possible
    void push(const T &item){
        std::shared_ptr<Node> oldfirst(first);
        first = std::make_shared<Node>(item, oldfirst);
        num++;
    }
    T pop(){
        if(first == nullptr)throw(first);
        T item = first->item;
        first = first->next;
        num--;
        return item;
    }
};
