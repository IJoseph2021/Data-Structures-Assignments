#ifndef NODE_H
#define NODE_H

template <class T>
class Node{
template <class U> friend class DoubleLinkedList;
private:
    T data;
    Node<T>* next;
    Node<T>* prev;
public:
    Node(T a);

};
template <class T>
Node<T>::Node(T a){
    next = nullptr;
    prev = nullptr;
    data = a;
}



#endif // NODE_H
