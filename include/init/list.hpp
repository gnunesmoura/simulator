#ifndef LIST_H
#define LIST_H

template <class T>
class List {
private:
    template <class T>
    class Node {
    public:
        T value;
        Node<T> * next;
        Node<T> * prev;
        Node() {
            next = NULL;
            prev = NULL;
        }
        ~Node();
    };


    Node<T> * head;
    Node<T> * tail;

public:
    LinkedList(): head(NULL), tail(NULL) {}
    ~LinkedList();
    void push();
    
};

#endif
