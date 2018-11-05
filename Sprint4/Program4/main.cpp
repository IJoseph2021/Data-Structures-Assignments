#define CATCH_CONFIG_RUNNER

//include statements
#include "catch.hpp"
#include <iostream>
#include "doublelinkedlist.h"
#include "node.h"
#include "stack.h"
#include <fstream>
#include <string>
#include "adjacencylist.h"
#include <sstream>
using namespace std;

//adjaency list declaration
AdjacencyList <string> master;
int arrCount = 0;
ofstream myFile3;

//catch
int runCatchTests(int agc, char* const argv[]){
    return Catch::Session().run();
}
//function prototypes
void iterativeBackTrack(string a, string b);
int* distanceFinder(string *a);
string* sortData(string a [], string b [], int e);
string checkInput(string a);

//main method with command line arguments passed in
int main(int argc, char* argv[])
{
    //if the first argument is "-t" then perform Catch TDD
    if(strcmp (argv[1], "-t") == 0){
        Catch::Session().run();
    }
    else{
        ifstream myFile;
        int x = 0;
        string hold;
        myFile3.open(argv[4]);

        //read in data from frist file
        myFile.open(argv[2]);
        if(myFile.is_open()){
            getline(myFile, hold);
            stringstream convert(hold);
            convert>>x;
            string *a = new string[x];
            string *b = new string[x];
            int y = 0;

            while(y<x){
              getline(myFile, hold, '|');
              //check if there is any garbage in input
              a[y] = checkInput(hold);
              getline(myFile, hold);        
              b[y] = checkInput(hold);
              y++;
            }
            for(int i  = 0; i<x;i++){
                cout<<a[i]<<"|"<<b[i]<<endl;
                master.insertFor(a[i], b[i]);
                master.insertFor(b[i], a[i]);
            }
            master.printList();
            //sort the names and find unique names
            string* r = sortData(a, b, x);
            //find all people that have a max disttance of two from eachother
            int * e = distanceFinder(r);
            for(int i = 0; i<arrCount; i++){
              cout<<r[i]<<":"<<e[i]<<endl;
              myFile3<<r[i]<<":"<<e[i]<<endl;
            }
            delete []a;
            delete []b;
        }


        ifstream myFile2;
        myFile2.open(argv[3]);
        //open data connections file read in data
        if(myFile2.is_open()){

            getline(myFile2, hold);
            stringstream convert(hold);
            convert>>x;
            string *a = new string[x];
            string *b = new string[x];
            int y = 0;
            while(y<x){

              getline(myFile2, hold, '|');
              a[y] = checkInput(hold);
              getline(myFile2, hold);
              b[y] = checkInput(hold);
              y++;
            }
            //perform iterative backtracking to fins shortest path
            for(int i = 0; i<x; i++){
              iterativeBackTrack(a[i], b[i]);
            }
            delete []a;
            delete []b;

        }

    }

}

//check input for garbage characters
string checkInput(string a){
    for(int i =0; i<a.length(); i++){
        if(a[i] == '\n' || a[i] == '\r'){
            a.erase(i);
        }
    }
    return a;
}

//perform iterative backtrack
void iterativeBackTrack(string a, string b){
    Stack <string> holder;
    string target = b;
    string top;
    string source = a;
    holder.push(source);
    int x = 1000;

    //reset iterator
    for(int i = 1; i<=master.returnSize(); i++){
        master[i].resetIterator();
    }
    //while stack is empty
    while(holder.isEmpty()== false){
        if(holder.returnTop() == target){
            //end if path is founs
            if(holder.returnCount()-1 < x){
                x = holder.returnCount()-1;

            }
           
            string y = holder.pop();
            
        }
        else{
            //step iterator
            master.returnList(holder.returnTop()).stepIterator();

            //push next person if it is not already on stack
            while(master.returnList(holder.returnTop()).iterNull() == false && holder.searchStack(master.returnList(holder.returnTop()).returnIterator()) == true){
                master.returnList(holder.returnTop()).stepIterator();
            }
            if(master.returnList(holder.returnTop()).iterNull() == false){
                holder.push(master.returnList(holder.returnTop()).returnIterator());
            }

            //if it is then pop
            else{
                master.returnList(holder.returnTop()).resetIterator();
                string r = holder.pop();
            }
        }
    }
    cout<<a<<"|"<<b<<": "<<x<<endl;
    myFile3<<a<<"|"<<b<<": "<<x<<endl;
}

//sort people alpha. and then take out duplicates
string* sortData(string a[], string b[], int e){
    Stack <string> holder;
    for(int i =0; i<e; i++){
        if(holder.searchStack(a[i]) == false){
            holder.push(a[i]);
            arrCount++;
        }
        if(holder.searchStack(b[i]) == false){
            holder.push(b[i]);
            arrCount++;
        }
    }
    string* c = new string[arrCount];
    int l = holder.returnCount();
    for(int i = 0; i<l; i++){
        c[i]= holder.pop();
    }

    for(int i =0; i<arrCount-1; i++){
        for(int j = 0; j<arrCount-i-1; j++){
            if(c[j]>c[j+1]){
                swap(c[j], c[j+1]);
            }
        }
    }
    return c;
}


//finds all people who have a distance of two from eachother
int* distanceFinder(string *a){
    string d;
    Stack <string> tempHolder;
    int b = arrCount;
    int *c = new int[arrCount];
    int uniqueCount = 0;
    for(int i =0; i<b; i++){
        d = a[0];
        for(int j =1; j<=master.returnList(d).returnSize(); j++){
            string q = (master.returnList(d))[j];
            if(tempHolder.searchStack(master.returnList(d)[j]) == false){
                tempHolder.push(master.returnList(d)[j]);
                uniqueCount++;
            }
            for(int k = 1; k<=master.returnList(master.returnList(d)[j]).returnSize(); k++){
                if(tempHolder.searchStack(master.returnList(master.returnList(d)[j])[k]) == false){
                    tempHolder.push(master.returnList(master.returnList(d)[j])[k]);
                    uniqueCount++;
                }
            }
        }
        c[i] = uniqueCount - 2;
        uniqueCount = 0;
        tempHolder.clearStack();
    }

    return c;
}


