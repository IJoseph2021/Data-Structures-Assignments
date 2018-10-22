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
    ~Node();
};
template <class T>
Node<T>::Node(T a){
    next = nullptr;
    prev = nullptr;
    data = a;
}
template <class T>
Node<T>::~Node(){

}


#endif // NODE_H
