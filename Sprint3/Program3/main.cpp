#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int y =0;
void sortVector(string **a, int b[], string c[]);
int partitionVector(string a[], int b, int c, int d);
void quickSortVector(string a [], int b, int c, int d);
//void insertionSort(string arr[], int n);
void bubbleSort(string arr[], int n);






int main(int argc, const char *argv[])

{
    ifstream myfile;
    ofstream myfile2;
    string a ="";
    srand (time(NULL));
    myfile.open(argv[1]);
    getline(myfile, a);
    stringstream input1(a);
    int y =0;
    input1>>y;
    getline(myfile, a);
    stringstream input(a);
    int x =0;
    input>>x;
    string ** arr = new string* [31];
    for(int i =0; i<31;i++){
        arr[i] = new string[y/5];
    }
    int* arrCount  = new int [31];
    string* hold = new string[y+1];
    int q =0;
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile, a);
            hold[q] = a;
            q++;
        }
        cout<<"Yikers:"<<q<<endl;
    }
   myfile.close();
   sortVector(arr, arrCount, hold);
   delete []hold;
   for(int i =0; i<31; i++){
       quickSortVector(arr[i], 0, arrCount[i]-1, arrCount[i]);
       //insertionSort(arr[i], (sizeof(arr[i])/sizeof(arr[i][0])));
       //bubbleSort(arr[i], arrCount[i]);
   }
    myfile2.open(argv[2]);
    if(myfile2.is_open()){
        for(int i =0; i<31; i++){
            for(int j =0; j<arrCount[i]; j++){
                myfile2<<arr[i][j]<<endl;
                x--;
                if(x<1){
                    goto label;
                }
            }
        }
    }
    label:
    myfile2.close();
    delete []arr;
    return 0;
}



void sortVector(string **a, int b[], string c[]){
    int x = 0;
    int counter =0;
    for(int i =0; i<31; i++){
        b[i] =0;
    }
    for(int i =0; i<y; i++){
        x = c[i].length()-1;
        a[x][b[x]] = c[i];
        b[x] = b[x] + 1;
    }
}




int partitionVector(string a[], int b, int c, int d){

    if(d>1){
        int random = b + rand() % (c - b);
        string pivot = a[random];
        int i = b - 1;
        int j = c + 1;
        while (true) {
            do {
                j--;
            } while (a[j] > pivot);
            do {
                i++;
            } while (a[i] < pivot);

            if (i < j){
                swap(a[i], a[j]);
            }
            else{
                return j;
            }
        }
    }
}


void quickSortVector(string a[], int b, int c, int d){
    int r;
    if(b<c){
        r = partitionVector(a,b, c, d);
        quickSortVector(a, b, r, d);
        quickSortVector(a, r+1, c, d);
    }
}

void insertionSort(string arr[], int n)
{
   int i,  j;
   string key;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void bubbleSort(string arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(arr[j], arr[j+1]);
}

