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
int y =0;
void sortVector(string **a, int b[]);
int partitionVector(string a[], int b, int c);
void quickSortVector(string a [], int b, int c);

fstream myfile;
ofstream myfile2;


int main(int argc, char *argv[])
{
    string a;
    srand (time(NULL));
    myfile.open(argv[1]);

    getline(myfile, a);
    stringstream input1(a);
    input1>>y;
    getline(myfile, a);
    stringstream input(a);
    int x =0;
    input>>x;
    string ** arr = new string* [20];
    for(int i =0; i<20;i++){
        arr[i] = new string[y];
    }
    int arrCount [20];
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile, a);
            hold.push_back(a);
        }
    }
   myfile.close();
   sortVector(arr, arrCount);
   for(int i =0; i<20; i++){
       quickSortVector(arr[i], 0, (sizeof(arr[i])/sizeof(arr[i][0]))-1);
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



void sortVector(string **a, int b[]){
    int x = 0;
    int counter =0;
    for(int i =0; i<sizeof(b)/sizeof(b[0]); i++){
        b[i] =0;
    }
    for(int i =0; i<hold.size(); i++){
        x = hold[i].length()-1;
        a[x][b[x]] = hold[i];
        b[x] = b[x] + 1;
    }
}




int partitionVector(string a[], int b, int c){

    if(sizeof(a)/sizeof(a[0])>1){
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


void quickSortVector(string a[], int b, int c){
    int r;
    if(b<c){
        r = partitionVector(a,b, c);
        quickSortVector(a, b, r);
        quickSortVector(a, r+1, c);
    }
}
