#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include "doublelinkedlist.h"

using namespace std;
template <class T>
class AdjacencyList{
private:
    DoubleLinkedList<DoubleLinkedList<T>> List;

public:
    void insertFor(T a, T b);
    void printList();
    int returnSize();
    DoubleLinkedList<T>& operator [](int a);
    DoubleLinkedList<T>& returnList(T a);
};

template <class T>
void AdjacencyList<T>::insertFor(T a, T b){
    for(int j = 1; j<=List.returnSize();j++){
        if(List[j][1] == a){
            List[j].insertBack(b);
            return;
        }
    }
    List.insertBack(DoubleLinkedList<T>());
    List[List.returnSize()].insertBack(a);
    List[List.returnSize()].insertBack(b);
}



template <class T>
void AdjacencyList<T>::printList(){
    for(int j = 1; j<=List.returnSize(); j++){
        List[j].printList();
        cout<<endl;
        cout<<"|"<<endl;
        cout<<"v"<<endl;
    }
}

template <class T>
int AdjacencyList<T>::returnSize(){
    return List.returnSize();
}

template <class T>
DoubleLinkedList<T>& AdjacencyList<T>::operator [](int a){
    return List[a];
}

template <class T>
DoubleLinkedList<T>& AdjacencyList<T>::returnList(T a){
    for(int i =1; i<=List.returnSize(); i++){
        if(List[i][1] == a){
            return List[i];
        }
    }
}

#endif // ADJACENCYLIST_H
