#include <iostream>
#include <time.h>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
//vector <string> hold;
//vector <vector<string>> wordLength (20);
//int y =0;
void sortVector(string **a, int b[], string c[]);
int partitionVector(string a[], int b, int c, int d);
void quickSortVector(string a [], int b, int c, int d);
void DualPivotQuickSort(string * arr, int low, int high);
int partition(string* arr, int low, int high, int* lp);
void optimizedQuickSort(string *arr, int b, int c, int d);
void insertionSort(string * arr, int b, int c);
//void insertionSort(string arr[], int n);
//void bubbleSort(string arr[], int n);
int y = 0;


//fstream myfile;
//fstream myfile2;


int main(int argc, const char *argv[])

{
    ifstream myfile;
    ofstream myfile2;
    string a ="";

    srand (time(NULL));
    myfile.open(argv[1]);
    getline(myfile, a);
    stringstream input1(a);
    //int y =0;
    input1>>y;
    getline(myfile, a);
    stringstream input(a);
    int x =0;
    input>>x;
    string ** arr = new string* [30];
    for(int i =0; i<20;i++){
        arr[i] = new string[y];
    }
    int* arrCount  = new int [30];
    string* hold = new string[y+1];
    int q =0;
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile, a);
            hold[q] = a;
            q++;
        }
    }
   myfile.close();
   sortVector(arr, arrCount, hold);
   delete []hold;
   for(int i =0; i<30; i++){

       //optimizedQuickSort(arr[i], 0, arrCount[i]-1, 750);
       insertionSort(arr[i], 0, arrCount[i] - 1);
       //insertionSort(arr[i], (sizeof(arr[i])/sizeof(arr[i][0])));
       //bubbleSort(arr[i], (sizeof(arr[i])/sizeof(arr[i][0])));
   }
    myfile2.open(argv[2]);
    if(myfile2.is_open()){
        for(int i =0; i<30; i++){
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
    delete arr;
    return 0;
}



void sortVector(string **a, int b[], string c[]){
    int x = 0;
    int counter =0;
    for(int i =0; i<30; i++){
        b[i] =0;
    }
    for(int i =0; i<y; i++){
        x = c[i].length()-1;
        a[x][b[x]] = c[i];
        b[x] = b[x] + 1;
    }
}



void DualPivotQuickSort(string * arr, int low, int high)
{
    if (low < high) {
        // lp means left pivot, and rp means right pivot.
        int lp, rp;
        rp = partition(arr, low, high, &lp);
        DualPivotQuickSort(arr, low, lp - 1);
        DualPivotQuickSort(arr, lp + 1, rp - 1);
        DualPivotQuickSort(arr, rp + 1, high);
    }
}

int partition(string* arr, int low, int high, int* lp)
{
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    // p is the left pivot, and q is the right pivot.
    int j = low + 1;
    int g = high - 1, k = low + 1;
    string p = arr[low], q = arr[high];
    while (k <= g) {

        // if elements are less than the left pivot
        if (arr[k] < p) {
            swap(arr[k], arr[j]);
            j++;
        }

        // if elements are greater than or equal
        // to the right pivot
        else if (arr[k] >= q) {
            while (arr[g] > q && k < g)
                g--;
            swap(arr[k], arr[g]);
            g--;
            if (arr[k] < p) {
                swap(arr[k], arr[j]);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;

    // bring pivots to their appropriate positions.
    swap(arr[low], arr[j]);
    swap(arr[high], arr[g]);

    // returning the indeces of the pivots.
    *lp = j; // because we cannot return two elements
             // from a function.

    return g;
}

void insertionSort(string * arr, int b, int c){
    for(int i = b + 1; i<=c; i++){
        string value = arr[i];
        int j =i;
        while(j>b && arr[j-1] > value){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = value;
    }
}

void optimizedQuickSort(string *arr, int b, int c, int d){
    if (b<c) {
        if ((c - b + 1) > d) {
            int lp, rp;
            rp = partition(arr, b, c, &lp);
            DualPivotQuickSort(arr, b, lp - 1);
            DualPivotQuickSort(arr, lp + 1, rp - 1);
            DualPivotQuickSort(arr, rp + 1, c);

        }
    }
}
