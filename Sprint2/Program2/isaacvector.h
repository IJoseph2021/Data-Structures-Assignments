#ifndef ISAACVECTOR_H
#define ISAACVECTOR_H

template <class T>
class IsaacVector
{
private:
    int size;
    int capacity;
    T* arrayPointer;

public:
    IsaacVector();
    IsaacVector(int a);
    IsaacVector(const IsaacVector<T>&);
    ~IsaacVector();
    void push_back(T );
    T& operator [](int a);
    IsaacVector& operator =(const IsaacVector<T>&);
    int returnSize();
    int returnCapactiy();
};

template<class T>
IsaacVector<T>::IsaacVector()
{
    size = 0;
    capacity = 10;
    arrayPointer = new T[capacity];
}

template<class T>
IsaacVector<T>::IsaacVector(int a)
{
    size = 0;
    capacity = a;
    arrayPointer = new T[capacity];
}

template<class T>
IsaacVector<T>::IsaacVector(const IsaacVector& a)
{
    size = a.size;
    capacity = a.capacity;
    arrayPointer = new T[capacity];
    for(int i =0; i<a.size; i++){
        arrayPointer[i] = a.arrayPointer[i];
    }
}

template<class T>
IsaacVector<T>::~IsaacVector()
{
    delete [] arrayPointer;
}

template<class T>
void IsaacVector<T>::push_back(T a){
    if(size+1>capacity){
        capacity = size*2;
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

template<class T>
T& IsaacVector<T>::operator [](int a)
{
    return arrayPointer[a];
}

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
int IsaacVector<T>::returnSize(){
    return size;
}

template <class T>
int IsaacVector<T>::returnCapactiy(){
    return capacity;
}


#endif // ISAACVECTOR_H

