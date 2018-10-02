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
vector <vector<string>> wordLength (20);
void sortVector(string *a, int b);
int partitionVector(vector<string>&a, int b, int c);
void quickSortVector(vector<string>& a, int b, int c);

fstream myfile;
ofstream myfile2;
int main(int argc, char *argv[])
{

    string a;
    srand (time(NULL));
    myfile.open(argv[1]);
    getline(myfile, a);
    stringstream input(a);
    int y =0;
    input>>y;
    string * hold = new string[y+1];
    getline(myfile, a);
    stringstream input1(a);
    int x =0;
    input1>>x;
    int q =0;
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile, a);

            //hold.push_back(a);
            hold[q] = a;
            q++;
        }
    }
   myfile.close();
   sortVector(hold, y+1);
   for(int i =0; i<wordLength.size(); i++){
       quickSortVector(wordLength[i], 0, wordLength[i].size()-1);
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

void sortVector(string *a, int b){
    int x = 0;
    for(int i =0; i<b; i++){
        x = a[i].length()-1;
        wordLength[x].push_back(a[i]);
    }
}

int partitionVector(vector<string> &a, int b, int c){

    if(a.size()>1){
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


void quickSortVector(vector<string> &a, int b, int c){
    int r;
    if(b<c){
        r = partitionVector(a,b, c);
        quickSortVector(a, b, r);
        quickSortVector(a, r+1, c);
    }
}
