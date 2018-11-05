#ifndef STACK_H
#define STACK_H
#include "doublelinkedlist.h"

template <class T>
class Stack{
private:
    DoubleLinkedList<T> stuff;
    int count;
public:
    void push(T a);
    bool isEmpty();
    T pop();
    Stack();
    T returnTop();
    int returnCount();
    bool searchStack(T a);
    void clearStack();
};

template <class T>
Stack<T>::Stack(){
    count = 0;
}

template <class T>
void Stack<T>::push(T a){
    stuff.insertFront(a);
    count++;
}

template <class T>
T Stack<T>::pop(){
    T first = stuff[1];
    stuff.removeFront();
    count--;
    return first;
}

template <class T>
bool Stack<T>::isEmpty(){
    if(stuff.returnSize() == 0){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
T Stack<T>::returnTop(){
    return stuff[1];
}

template <class T>
int Stack<T>::returnCount(){
    return count;
}

template <class T>
bool Stack<T>::searchStack(T a){
    for(int i = 1; i<=count; i++){
        if(stuff[i] == a){
            return true;
        }
    }
    return false;
}

template <class T>
void Stack<T>::clearStack(){
    for(int i = 0; i<count; i++){
        stuff.removeFront();

    }
    count = 0;
}
#endif // STACK_H
