//include statements
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//a bunch of different sorting algorithms
void sortVector(string **a, int b[], string c[], int q);
int partitionVector(string a[], int b, int c, int d);
void quickSortVector(string a [], int b, int c, int d);
void DualPivotQuickSort(string * arr, int b, int c);
int partition(string* arr, int b, int c, int* lp);
void optimizedQuickSort(string *arr, int b, int c, int d);
void insertionSort(string * arr, int b, int c);
void optimizedQuickSort2(string *arr, int b, int c, int d, int e);

//helpful functions
int convertToInt(string a);
//picks a sort algorithm to use
void sortAndPickAlgorithm(string ** arr, int arrCount[]);




int main(int argc, const char *argv[])

{
    //create ifstream/output file for input/output
    ifstream myfile;
    ofstream myfile2;
    string a ="";

    //seed random time
    srand (time(NULL));
    //read in first two lines to see how much to read and write
    myfile.open(argv[1]);
    getline(myfile, a);
    int y = convertToInt(a);
    getline(myfile, a);
    int x =convertToInt(a);

    //dynamically allocate a double pointer array to hold the sorted data
    string ** arr = new string* [31];
    for(int i =0; i<20;i++){
        arr[i] = new string[y];
    }

    //allocate an int array to keep track of the number of words in each bucket
    int* arrCount  = new int [31];

    //create array to hold in all read in data
    string* hold = new string[y+1];
    int q =0;
    //read in data
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile, a);
            hold[q] = a;
            q++;
        }
    }

   myfile.close();

   //sort the array first by length
   //transfer data to the 2d array
   sortVector(arr, arrCount, hold, y);

   //free memory
   delete []hold;

   //after array is sorted by length, sort the 2d array
   sortAndPickAlgorithm(arr, arrCount);
   //print data to file
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
    delete []arrCount;
    return 0;
}


//sort array by length
void sortVector(string **a, int b[], string c[], int q){
    int x = 0;
    for(int i =0; i<31; i++){
        b[i] =0;
    }
    //add words to their corresponding array bucket and increment the array that is holding the counters
    for(int i =0; i<q; i++){
        x = c[i].length()-1;
        a[x][b[x]] = c[i];
        b[x] = b[x] + 1;
    }
}


//dual pivot quicksort
//instead of picking 1 pivot, two pivots are picked
//recurively called like quicksort
//sort from beginning to left pivot, left pivot to right pivot
//sort from right pivot to end
void DualPivotQuickSort(string * arr, int b, int c)
{
    if (b < c) {
        int lpivot = 0;
        int rpivot = 0;
        rpivot = partition(arr, b, c, &lpivot);
        DualPivotQuickSort(arr, b, lpivot - 1);
        DualPivotQuickSort(arr, lpivot + 1, rpivot - 1);
        DualPivotQuickSort(arr, rpivot + 1, c);
    }
}

//this is the partition scheme for the dual pivot method
//sort works by taking two pivots and setting up the array into three sections
//the first pivot will be smaller than the second
//first group contains all values less than first pivot
//second group contains all values greater than fp but less than second pivot
//thirs group contains all values greater than third pivot
int partition(string* arr, int b, int c, int* lp)
{

    /*if (arr[b] > arr[c]){
        swap(arr[b], arr[c]);
    }*/
    // p is the left pivot, and q is the right pivot.
    int j = b + 1;
    int g = c - 1;
    int k = b + 1;
    int random = b + rand() % (c - b);
    int random2 = b + rand() % (c - b);
    if (arr[random] > arr[random2]){
        swap(arr[random], arr[random2]);
    }
    string p = arr[random];
    string q = arr[random2];

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


    swap(arr[b], arr[j]);
    swap(arr[c], arr[g]);

    // returning the indece
    *lp = j;
    return g;
}

//insertion sort
void insertionSort(string * arr, int b, int c){
    for(int i = b + 1; i<=c; i++){
        string hold = arr[i];
        int j =i;
        while(j>b && arr[j-1] > hold){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = hold;
    }
}

//optimizedquicksort for the dual pivot sort
//if the array is small enough then call insertion sort
//else just use dualpivotquicksort
void optimizedQuickSort(string *arr, int b, int c, int d){
    if (b<c) {
        if ((c - b + 1) > d) {
            int lpivot = 0;
            int rpivot = 0;
            rpivot = partition(arr, b, c, &lpivot);
            DualPivotQuickSort(arr, b, lpivot - 1);
            DualPivotQuickSort(arr, lpivot + 1, rpivot - 1);
            DualPivotQuickSort(arr, rpivot + 1, c);
        }
    }
}

//parition array useing random pivot

int partitionVector(string * a, int b, int c, int d){
    //d makes sure that arry is greater than 0
    if(d>1){
        //pick random pivot
        int random = b + rand() % (c - b);
        string pivot = a[random];
        int i = b - 1;
        int j = c + 1;
        //this takes two values on the beginning and end of array
        //the indexes of values appraoch each other, until a smaller thing is on right side and larger thing is on left side
        //then the two elements are swapped
        //return the pivot indice
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

//regular quicksort recursive function
void quickSortVector(string *a, int b, int c, int d){
    int r;
    if(b<c){
        r = partitionVector(a,b, c, d);
        quickSortVector(a, b, r, d);
        quickSortVector(a, r+1, c, d);
    }
}

//optimized quicksort2
//this optimization is for the quicksort with random pivot
void optimizedQuickSort2(string *arr, int b, int c, int d, int e){
    while (b<c) {
        //if the array is small enough use insertion sort
        if ((c - b ) < e) {
            insertionSort(arr, b, c);
            break;
        }
        else{
            //if not then use the standard recusion scheme of quicksort

            int pivot = partitionVector(arr, b, c, d);
            //this is called tail handling and prioritzed sorting smalelr arrays
            if(pivot - b < c - pivot){
                optimizedQuickSort2(arr, b, pivot - 1, d, e);
                b = pivot + 1;
            }
            else{
                optimizedQuickSort2(arr, pivot + 1, c, d, e);
                c = pivot - 1;
            }
       }
    }
}

//convert a string to int
int convertToInt(string a){
    int b =0;
    stringstream input (a);
    input >> b;
    return b;
}

//sort each array and implement sorting algorithm
void sortAndPickAlgorithm(string ** arr, int arrCount[]){
    for(int i =0; i<31; i++){
       // radixSort(arr[i], (int)arrCount[i]);
        //optimizedQuickSort(arr[i], 0, arrCount[i]-1, 120);
        optimizedQuickSort2(arr[i], 0, arrCount[i]-1, arrCount[i], 120);
        //insertionSort(arr[i], 0, arrCount[i] - 1);
        //DualPivotQuickSort(arr[i], 0, arrCount[i]-1);
        //insertionSort(arr[i], (sizeof(arr[i])/sizeof(arr[i][0])));
        //bubbleSort(arr[i], (sizeof(arr[i])/sizeof(arr[i][0])));
    }
}
