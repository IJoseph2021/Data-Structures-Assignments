#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
using namespace std;
fstream myfile;
ofstream myfile2;

vector <string> hold;
vector <vector<string>> wordLength (20);
void sortVector();
void bubbleSort(vector<string>&a, int b);
int main(int argc, char* argv[1])
{
    string a;
    myfile.open(argv[1]);
    getline(myfile, a);
    getline(myfile, a);
    stringstream input(a);
    int x = 0;
    input >> x;
    if (myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile, a);
            hold.push_back(a);
        }
    }
    myfile.close();
    sortVector();
    for(int i =0; i<wordLength.size(); i++){
        bubbleSort(wordLength[i], wordLength[i].size());
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
}

void sortVector(){
    int x = 0;
    for(int i =0; i<hold.size(); i++){
        x = hold[i].length()-1;
        wordLength[x].push_back(hold[i]);
    }
}

void bubbleSort(vector<string> &a, int b){
    for(int i =0; i<b-1; i++){
        for(int j = 0; j<b - i - 1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}
