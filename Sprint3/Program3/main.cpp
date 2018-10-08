#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//a bunch of different sorting algorithms
void sortVector(string **a, int b[], string c[], int q);
inline int partitionVector(string a[], int b, int c, int d);
void quickSortVector(string a [], int b, int c, int d);
void optimizedQuickSort2(string *arr, int b, int c, int d, int e);
void bubbleSort(string arr[], int b, int c);



//helpful functions
int convertToInt(string a);
//picks a sort algorithm to use
void sortAndPickAlgorithm(string ** arr, int arrCount[]);




int main(int argc, const char *argv[])

{
    //create ifstream/output file for input/output
    ifstream myfile;
    ofstream myfile2(argv[2], std::ofstream::binary);
    //ofstream myfile2;
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
    //due to heap limitations on my VM, if the file is more than 1 mil words long, then each sub array will have y/4 length, instead of y length
    string ** arr = new string* [31];
    if(y<1000000){
        for(int i =0; i<31; i++){
            arr[i] = new string [y];
        }
    }
    else{
        for(int i =0; i<31;i++){
            arr[i] = new string[y/4];
        }
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

    //after array is sorted by length, sort the entire 2d-multi dimensional array using whatever algorithm
    sortAndPickAlgorithm(arr, arrCount);

    //print data to file using buffer
    int counter = 0;
    int totalSize = (y*31)+1;
    //create a buffer of maxsize
    //put each character of each string in each array in the buffer
    //after each word put a new line character
    char * buffer = new char[totalSize];
    for(int i =0; i<31; i++){
        for(int j = 0; j<arrCount[i]; j++){
            for(int k =0; k<arr[i][j].length(); k++){
                buffer[counter] = arr[i][j][k];
                counter ++;
            }
            //x is the second line that was read in on the file that sayd how many strings to print out
            x--;
            if(x<1){
                goto label;
            }
            buffer [counter] = '\n';
            counter ++;
        }
    }
    label:
    myfile2.write(buffer, counter);
    myfile2.close();

    //free all dynamically allocated memory
    for(int i =0; i<31;i++){
        delete []arr[i];
    }
    delete []arr;
    delete []arrCount;
}


//sort array by length
void sortVector(string **a, int b[], string c[], int q){
    int x = 0;
    //initliaze each bucket to 0, meaning their are no words in them
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

//parition array using Median Pivot
inline int partitionVector(string * a, int b, int c, int d){
    //d makes sure that arry is greater than 0
    if(d>1){

        //median pivot strategy
        string u = a[b];
        string o = a[c];
        string p = a[(b+c)/2];
        string pivot;
        if((u<o && u>p) || (u>o && u<p)){
            pivot = u;
        }
        else if((o<u && o>p) || (o>u && o<p)){
            pivot = o;
        }
        else{
            pivot = p;
        }

        //set bounds for the beginning and end of array
        int i = b - 1;
        int j = c + 1;
        //this takes two values on the beginning and end of array
        //thw while loops increment the indexes until a smaller value is on right side and larger value is on left side
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
        //get pivot
        r = partitionVector(a,b, c, d);
        quickSortVector(a, b, r, d);
        quickSortVector(a, r+1, c, d);
    }
}

//optimized quicksort2
//this optimization is two-fold
//after a certain number of partitions have been made on the original array, they subsequent arrays will be much smaller
//If these arrays are small enough, then a bubble sort will be automatically used for high performance
//additionally tail handling will prioritize sorting smaller arrays
void optimizedQuickSort2(string *arr, int b, int c, int d, int e){
    if (b<c) {
        //if the array is small enough use bubble sort
        if ((c - b ) < e) {
            bubbleSort(arr, b, c);

        }
        else{
            //if not then use the standard recusion scheme of quicksort

            int pivot = partitionVector(arr, b, c, d);
            //this is called tail handling and prioritzed sorting smalelr arrays
            optimizedQuickSort2(arr, b, pivot, d, e);
            optimizedQuickSort2(arr, pivot + 1,c, d, e);
       }
    }
}

//convert a string to int by putting string into stringstream
int convertToInt(string a){
    int b =0;
    stringstream input (a);
    input >> b;
    return b;
}

//sort each array and implement sorting algorithm
void sortAndPickAlgorithm(string ** arr, int arrCount[]){
    for(int i =0; i<31; i++){
        optimizedQuickSort2(arr[i], 0, arrCount[i]-1, arrCount[i], 30);
        //bubbleSort(arr[i], 0, arrCount[i] - 1);
        //quickSortVector(arr[i], 0, arrCount[i] - 1, arrCount[i]);
    }
}

//standard bubblsort
void bubbleSort(string arr[], int b, int c)
{
   int i, j;
   for (i = b; i < c; i++){

       for (j = b; j < c-i ; j++){
           if (arr[j] > arr[j+1])
              swap(arr[j], arr[j+1]);
        }
    }
}
