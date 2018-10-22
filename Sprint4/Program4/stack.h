#ifndef STACK_H
#define STACK_H
#include "doublelinkedlist.h"

class Stack{
private:
    DoubleLinkedList<std::string> stuff;
    int count;
public:
    void push(std::string a);
    std::string pop();
    Stack();
};

Stack::Stack(){
    count = 0;
}

void Stack::push(std::string a){
    stuff.insertFront(a);
}

std::string Stack::pop(){
    std::string first = stuff[1];
    stuff.removeFront();
    return first;
}
#endif // STACK_H
