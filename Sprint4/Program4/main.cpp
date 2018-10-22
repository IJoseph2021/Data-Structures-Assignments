#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include <iostream>
#include "doublelinkedlist.h"
#include "node.h"
#include "stack.h"
#include "adjacencylist.h"
using namespace std;


int runCatchTests(int agc, char* const argv[]){
    return Catch::Session().run();
}

//main method with command line arguments passed in
int main(int argc, char* argv[])
{
    //if the first argument is "-t" then perform Catch TDD
    if(strcmp (argv[1], "-t") == 0){
        Catch::Session().run();
    }
    else{
    DoubleLinkedList<int> a;
    cout<<a.returnSize()<<endl;
    a.insertFront(7);
    cout<<a.returnSize()<<endl;
    a.insertFront(5);
    cout<<a.returnSize()<<endl;
    a.insertFront(3);
    cout<<a.returnSize()<<endl;
    //cout<<"Value:"<<a[4]<<endl;
    a.insertAtIndex(3, 10);
    cout<<"Value:"<<a[4]<<endl;
    DoubleLinkedList<int> b;
    b  = a;
    cout<<b.returnSize()<<endl;
    cout<<"Value:"<<a[4]<<endl;
    cout << "Hello World!" << endl;
    return 0;
    }
}


