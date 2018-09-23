#include "isaacvector.h"

IsaacVector::IsaacVector()
{
    size = 0;
    capacity = 0;
    arrayPointer = new T[capacity];
}

IsaacVector::IsaacVector(int a)
{
    size = 0;
    capacity = a;
    arrayPointer = new T[capacity];
}

IsaacVector::IsaacVector(const IsaacVector& a)
{
    size = a.size;
    capacity = a.capacity;
    arrayPointer = new T[capacity];
    for(int i =0; i<a.size; i++){
        arrayPointer[i] = a.arrayPointer[i];
    }
}

IsaacVector::~IsaacVector()
{
    delete [] arrayPointer;
}

void IsaacVector::push_back(T a){
    if(size+1>capacity){
        //
    }
    arrayPointer[size] = a;
    size++;
}

T IsaacVector::operator [](int a)
{
    return arrayPointer[a];
}

T IsaacVector::operator= (const IsaacVector &a)
{
    size = a.size;
    capacity = a.capacity;
    delete [] arrayPointer;
    arrayPointer = new T[capacity];
    for(int i =0; i<a.size; i++){
        arrayPointer[i] = a.arrayPointer[i];
    }
    return *this;
}


