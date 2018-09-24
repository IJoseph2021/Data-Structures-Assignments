#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include "isaacvector.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <istream>
#include <vector>
#include <algorithm>
#include "index.h"
#include "isaacvector.h"

using namespace std;

void loadIntoVector();
void parse();
void addToVector(string a, int b);
void printIndex();
string makeLowerCase(string a);
void sortVector();
void printSortedVector();
bool checkIfGoodInput(char a);


IsaacVector <string> hold;
IsaacVector <Index> objects;
ifstream myFile("Output1.txt");


int runCatchTests(int agc, char* const argv[]){
    return Catch::Session().run();
}

void parseFile();

int main(int argc, char* argv[])
{
    if(strcmp (argv[1], "-t") == 0){
        Catch::Session().run();
    }
    else if (strcmp (argv[1], "-r") == 0){
        if(myFile.is_open()){
            while(!myFile.eof()){
                loadIntoVector();
            }
        }

        parse();
        sortVector();
        //printIndex();
        printSortedVector();
        return 0;
    }
    return 0;
}

string makeLowerCase(string a){
    string b = "";
    locale c;
    for(int i =0; i<a.length(); i++){
        b = b + tolower(a[i], c);
    }
    return b;
}

void printIndex(){
    for(int i =1; i<objects.returnSize(); i++){
        objects[i].printPages();
    }
}
void loadIntoVector(){
    string a;
    getline(myFile, a);
    hold.push_back(a);
    cout<<a<<endl;
}

bool checkIfGoodInput(char a){
    if(isalpha(a) || a == '\'' || isdigit(a)){
        return true;
    }
}

void addToVector(string a, int b){
    for(int i =0; i<objects.returnSize(); i++){
        if(objects[i].getWord() == a){
            if(objects[i].findPaperDuplicate(b) == true ){
                return;
            }
            objects[i].addPage(b);
            return;
        }
    }
    objects.push_back(Index(a, b));
}


void printSortedVector(){
    char x = 54234566;
    char a = '*';
    for(int i = 1; i<objects.returnSize()-2; i++){
        if(objects[i].getWord()[0] == a){
            objects[i].printPages();
        }
        else{
            a = objects[i].getWord()[0];
            char b = toupper(a);
            cout<<"["<<b<<"]"<<endl;
            objects[i].printPages();
        }
    }
}

void parse(){
    int x;
    string s;
    for(int i =0; i<hold.returnSize();i++){
        if(hold[i][0] == '<'){
            s = hold[i];
            s.erase(remove(s.begin(), s.end(), '<'), s.end());
            s.erase(remove(s.begin(), s.end(), '>'), s.end());
            stringstream number(s);
            number>>x;
        }
        else{
            int n =0;
            for(int j =0; j<hold[i].length(); j++){
                if(hold[i][j] == '['){
                    n++;
                }
            }
            string otherWords ="";
            IsaacVector<string> bracketString;
            if(n==0){
                for(int j =0; j<hold[i].length();j++){
                    string f = "";
                    if(isalpha(hold[i][j]) || isdigit(hold[i][j]) || hold[i][j] == '\'' || hold[i][j] == '-'){
                        while(isalpha(hold[i][j]) || isdigit(hold[i][j]) || hold[i][j] == '\'' || hold[i][j] == '-'){
                            f = f + hold[i][j];

                            j++;
                        }
                        f = makeLowerCase(f);
                        addToVector(f, x);

                    }
                }

            }
            while(n>0){
                string b;
                string c;
                stringstream convert(hold[i]);
                getline(convert, b, '[');
                getline(convert, c, ']' );
                bracketString.push_back(c);
                otherWords = otherWords + b;
                getline(convert, b, '[');
                otherWords = otherWords + b;
                n = n -1;
            }
            for(int i =0; i<bracketString.returnSize(); i++){
                string f = "";
                for(int j =0; j<bracketString[i].length();j++){

                    if(isalpha(bracketString[i][j]) || isdigit(bracketString[i][j]) || bracketString[i][j] == '\'' || bracketString[i][j] == '-' || bracketString[i][j] == ' '){
                        while(isalpha(bracketString[i][j]) || isdigit(bracketString[i][j]) || bracketString[i][j] == '\'' || bracketString[i][j] == '-' || bracketString[i][j] == ' '){
                            f = f + bracketString[i][j];
                            j++;
                        }
                        f = makeLowerCase(f);

                    }
                }
                bracketString[i] = f;
                bracketString[i] = makeLowerCase(bracketString[i]);
                addToVector(bracketString[i], x);
            }
            for(int j =0; j<otherWords.length();j++){
                string f = "";
                if(isalpha(otherWords[j]) || isdigit(otherWords[j]) || otherWords[j] == '\'' || otherWords[j] == '-'){
                    while(isalpha(otherWords[j]) || isdigit(otherWords[j]) || otherWords[j] == '\'' || otherWords[j] == '-'){
                        f = f + otherWords[j];

                        j++;
                    }
                    f = makeLowerCase(f);
                    addToVector(f, x);

                }
            }

        }
    }
}

void sortVector(){
    Index temp;
    for(int i =0; i<objects.returnSize()-1; i++){
        for(int j = 1; j<objects.returnSize(); j++){
            if(objects[i].getWord() < objects[j].getWord()){
                temp = objects[i];
                objects[i] = objects[j];
                objects[j] = temp;
            }
        }
    }
}
