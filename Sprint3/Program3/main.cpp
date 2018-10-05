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
vector <string> hold;
vector <vector<string>> wordLength (20);
void sortVector();
const int RUN = 32;
int partitionVector(vector<string>&a, int b, int c);
void quickSortVector(vector<string>& a, int b, int c);
void insertionSort(vector <string> &arr, int left, int right);
void merge(vector <string> &arr, int l, int m, int r);
void timSort(vector <string> &arr, int n) ;
void DualPivotQuickSort(vector <string> &arr, int low, int high);
int partition(vector <string> &arr, int low, int high, int* lp);
void partition(vector<string> & a, int l, int r, int &i, int &j) ;
void quicksort(vector <string> &a, int l, int r);


fstream myfile;
ofstream myfile2;
int main(int argc, char *argv[])
{

    string a;
    srand (time(NULL));
    myfile.open(argv[1]);
    getline(myfile, a);
    getline(myfile, a);
    stringstream input(a);
    int x =0;
    input>>x;
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile, a);
            hold.push_back(a);
        }
    }
   myfile.close();
   sortVector();
   for(int i =0; i<wordLength.size(); i++){
      quicksort(wordLength[i], 0, wordLength[i].size()-1);
   }
    myfile2.open(argv[2]);
    if(myfile2.is_open()){
        for(int i =0; i<wordLength.size(); i++){
            for(int j =0; j<wordLength[i].size(); j++){
                myfile2<<wordLength[i][j]<<endl;
                x--;
                if(x<1){
                    goto label;
                }
            }
        }
    }
    label:
    myfile2.close();
    return 0;
}


void sortVector(){
    int x = 0;
    for(int i =0; i<hold.size(); i++){
        x = hold[i].length()-1;
        wordLength[x].push_back(hold[i]);
    }
}

void partition(vector<string> & a, int l, int r, int &i, int &j)
{
    i = l-1, j = r;
    int p = l-1, q = r;
    string v = a[r];

    while (true)
    {
        // From left, find the first element greater than
        // or equal to v. This loop will definitely terminate
        // as v is last element
        while (a[++i] < v);

        // From right, find the first element smaller than or
        // equal to v
        while (v < a[--j])
            if (j == l)
                break;

        // If i and j cross, then we are done
        if (i >= j) break;

        // Swap, so that smaller goes on left greater goes on right
        swap(a[i], a[j]);

        // Move all same left occurrence of pivot to beginning of
        // array and keep count using p
        if (a[i] == v)
        {
            p++;
            swap(a[p], a[i]);
        }

        // Move all same right occurrence of pivot to end of array
        // and keep count using q
        if (a[j] == v)
        {
            q--;
            swap(a[j], a[q]);
        }
    }

    // Move pivot element to its correct index
    swap(a[i], a[r]);

    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i-1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);

    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i+1;
    for (int k = r-1; k > q; k--, i++)
        swap(a[i], a[k]);
}

// 3-way partition based quick sort
void quicksort(vector <string> &a, int l, int r)
{
    if (r <= l) return;

    int i, j;

    // Note that i and j are passed as reference
    partition(a, l, r, i, j);

    // Recur
    quicksort(a, l, j);
    quicksort(a, i, r);
}
