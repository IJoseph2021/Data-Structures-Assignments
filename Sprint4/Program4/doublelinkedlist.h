#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "node.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class DoubleLinkedList{
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *iter;
    int size;
public:
    DoubleLinkedList();
    DoubleLinkedList(T a);
    ~DoubleLinkedList();
    DoubleLinkedList(const DoubleLinkedList<T>&);
    T& operator [](int a);
    void insertBack(T a);
    void insertFront(T a);
    void insertAtIndex(int a, T b);
    void clear();
    void removeFront();
    void removeBack();
    DoubleLinkedList<T>& operator =(const DoubleLinkedList<T>&);
    int returnSize();
    void printList();
    void resetIterator();
    void stepIterator();
    T& returnIterator();
    bool iterNull();
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(){
    head = nullptr;
    tail = nullptr;
    iter = head;
    size = 0;
}

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(T a){
    Node<T>* temp = new Node<T>(a);
    head = temp;
    tail = temp;
    iter = head;
    size = 1;
}

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T>& a){
    if(a.head == nullptr){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    else{
        size = 0;
        head = new Node<T>(a.head->data);
        Node<T>* temp = a.head;
        Node<T>* tempNext = a.head->next;
        size++;
        while(tempNext != nullptr){
            temp->next = new Node<T>(tempNext->data);
            temp = temp->next;
            tempNext = tempNext->next;
            size++;
        }
        tail = temp;
    }
}

template<class T>
DoubleLinkedList<T> &DoubleLinkedList<T>::operator =(const DoubleLinkedList<T> &a){
    if(a.head == nullptr){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    else{
        size = 0;
        head = new Node<T>(a.head->data);
        Node<T>* temp = a.head;
        Node<T>* tempNext = a.head->next;
        size++;
        while(tempNext != nullptr){
            /*temp->next = new Node<T>(tempNext->data);
            temp = temp->next;
            tempNext = tempNext->next;*/
            temp = temp->next;
            this->insertBack(tempNext->data);
            size++;
        }
        tail = temp;
    }
    return *this;
}



template<class T>
DoubleLinkedList<T>::~DoubleLinkedList(){
    clear();
    delete head;
    //delete tail;
}

template<class T>
void DoubleLinkedList<T>::clear(){
    if(size==0){
        return;
    }
    while(head->next!=nullptr){
        removeFront();
    }
    size = 1;
}

template<class T>
void DoubleLinkedList<T>::removeBack(){
    if(head == nullptr){
        return;
    }
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        size --;
    }
    else{
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        size--;
    }
}


template<class T>
void DoubleLinkedList<T>::removeFront(){
    if(head == nullptr){
        return;
    }
    else if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        iter = nullptr;
        size --;
    }
    else{
        Node<T>* temp = head;
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        if(iter == temp){
            iter = head;
        }
        size--;
    }
}



template<class T>
void DoubleLinkedList<T>::insertBack(T a){
    if(head == nullptr){
        head = new Node<T>(a);
        tail = head;
        iter = head;
        size++;
    }
    else{
        Node<T>* temp = tail;
        tail->next = new Node<T>(a);
        tail->next->prev = tail;
        tail = tail->next;
        if(iter == temp){
            iter = temp;
        }
        size++;
    }
}

template<class T>
void DoubleLinkedList<T>::insertFront(T a){
    if(head == nullptr){
        head = new Node<T>(a);
        tail = head;
        iter = head;
        size++;
    }
    else{
        Node<T>* temp = head;
        head->prev = new Node<T>(a);
        head->prev->next = head;
        head = head->prev;
        if(iter == temp){
            iter = head;
        }
        size++;
    }
}

template<class T>
void DoubleLinkedList<T>::insertAtIndex(int a, T b){
    if(head == nullptr){
        insertFront(b);
        return;
    }
    Node<T>* curr = head;
    if(a>size){
        std::cout<<"Index is too large"<<std::endl;
        std::cout<<"size is: "<<size<<std::endl;
        return;
    }
    while(curr->next!=nullptr && a>1){
        curr = curr->next;
        a--;
    }
    if(curr==head){
        insertFront(b);
    }
    else if(curr == tail){
        insertBack(b);
    }
    else {
        Node<T>* temp = new Node<T>(b);
        temp->prev = curr;
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
    }
}

template <class T>
T& DoubleLinkedList<T>::operator [](int a)
{
    Node<T>* curr = head;
    if(a>size || a == 0){
        throw;
    }
    else{
        while(curr->next!=nullptr && a>1){
            curr = curr->next;
            a--;
        }
        return curr->data;
    }
}

template <class T>
int DoubleLinkedList<T>::returnSize(){
    return size;
}

template <class T>
void DoubleLinkedList<T>::printList(){
    Node<T>* curr = head;
    while(curr!=nullptr){
        cout<<curr->data<<"->";
        curr = curr->next;

    }
}

template <class T>
void DoubleLinkedList<T>::stepIterator(){
    iter = iter->next;
}

template <class T>
void DoubleLinkedList<T>::resetIterator(){
    iter = head;
}

template <class T>
bool DoubleLinkedList<T>::iterNull(){
    if(iter == nullptr){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
T& DoubleLinkedList<T>::returnIterator(){
    return iter->data;
}
#endif // DOUBLELINKEDLIST_H
