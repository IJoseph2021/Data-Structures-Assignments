#include "index.h"
using namespace std;
//include statements
#include <vector>
#include <string>
#include <iostream>

//constructor
Index::Index(){
    word = "";
}

//destructor
Index::~Index(){

}

//constructor with parameters
Index::Index(string a)
{
    word = a;
}

//constructor with more parameters
Index::Index(string a, int b){
    word = a;
    page.push_back(b);
}


//return page
int Index::accessPage(int a){
    return page[a];
}

//return word
string Index::getWord(){
    return word;
}

//set word
void Index::setWord(string a){
    word = a;
}

//add page to vector
void Index::addPage(int a){
    page.push_back(a);
}

//print out words and their pages that they occur on
void Index::printPages(){
    cout<<word<<": ";
    for(int i =0; i<page.size();i++){
        cout<<page[i]<<", ";
    }
    cout<<endl;
}

//return string that does the same thing the above method does
string Index::returnPages(){
    string s = word + ": ";
    for(int i =0; i<page.size();i++){
        if(i == page.size()-1){
            s = s + to_string(page[i]);
            return s;
        }
        s = s + to_string(page[i]) + ", ";
    }
    return s;
}

//checks to see if there the same page number occurs twice
bool Index::findPaperDuplicate(int b){
    for(int i =0; i<page.size(); i++){
        if(page[i] == b){
            return true;
        }
    }
}

//overloaded assignemnet operator that would not work with my vector
Index& Index::operator =(const Index &a){
    word = a.word;
    page.clear();
    for(int i =0; i<a.page.size(); i++){
        page.push_back(a.page[i]);
    }
    return *this;
}
