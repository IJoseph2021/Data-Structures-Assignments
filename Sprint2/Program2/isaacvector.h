#ifndef ISAACVECTOR_H
#define ISAACVECTOR_H

//templatize class
template <class T>
//class IsaacVector
class IsaacVector
{
private:
    //only three elements: size, capacity, and a pointer of type T to a dynaically allocated array
    int size;
    int capacity;
    T* arrayPointer;

public:
    IsaacVector();
    //constructor
    IsaacVector(int a);
    //copy constructor
    IsaacVector(const IsaacVector<T>&);
    //destructor
    ~IsaacVector();
    //push back
    void push_back(T );
    //overlaoded bracket operator
    T& operator [](int a);
    //overloaded assignment operator
    IsaacVector<T>& operator =(const IsaacVector<T>&);
    //return size of array
    int returnSize() const ;
    int returnCapacity() ;
    //clear the array
    void clearVect();
    T returnIndex(int a) const;
};

//contructor
//new array of that size is allocated
//similar to above but with a parameter
template<class T>
IsaacVector<T>::IsaacVector()
{
    size = 0;
    capacity = 0;
    arrayPointer = new T[0];
}

template<class T>
IsaacVector<T>::IsaacVector(int a)
{
    size = 0;
    capacity = a;
    arrayPointer = new T[capacity];
}

//copy constructor
//copy size and capacity
//iterate through array and copy each value
template<class T>
IsaacVector<T>::IsaacVector(const IsaacVector<T>& a)
{
    size = a.size;
    capacity = a.capacity;
    arrayPointer = new T[capacity];
    for(int i =0; i<a.size; i++){
        this->arrayPointer[i] = a.arrayPointer[i];
    }
}

//return Index
template<class T>
T IsaacVector<T>::returnIndex(int a) const{
    return arrayPointer[a];
}

//destructor
template<class T>
IsaacVector<T>::~IsaacVector()
{
    delete [] arrayPointer;
}

//clear vector
template<class T>
void IsaacVector<T>::clearVect(){
    delete [] arrayPointer;
}

//push back method
//if the size is greater than capacity
//double capacity and allocate a new array
//but make sure to store old array data in new array temp and then delete old data array
//and set pointer to point to temp
template<class T>
void IsaacVector<T>::push_back(T a){
    if(size+1 >= capacity){
        capacity = size*2 + 1;
        T* temp = new T[capacity];
        for(int i = 0; i<size; i++){
            temp[i] = arrayPointer[i];
        }
        delete []arrayPointer;
        arrayPointer = temp;
    }
    arrayPointer[size] = a;
    size++;
}

//overloaded bracket operator
template<class T>
T& IsaacVector<T>::operator [](int a)
{
    return arrayPointer[a];
}

//overloaded assignment operator
//like the copy constructor but return a pointer
template<class T>
IsaacVector<T> &IsaacVector<T>::operator =(const IsaacVector<T> &a)
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

template <class T>
int IsaacVector<T>::returnSize() const{
    return size;
}

template <class T>
int IsaacVector<T>::returnCapacity(){
    return capacity;
}
#endif // ISAACVECTOR_H
