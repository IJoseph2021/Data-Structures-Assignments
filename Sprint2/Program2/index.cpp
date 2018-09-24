#include "index.h"
using namespace std;
#include <vector>
#include <string>
#include <iostream>

Index::Index(){
    word = "";
}

Index::~Index(){

}
Index::Index(string a)
{
    word = a;
}

Index::Index(string a, int b){
    word = a;
    page.push_back(b);
}

int Index::accessPage(int a){
    return page[a];
}

string Index::getWord(){
    return word;
}

void Index::setWord(string a){
    word = a;
}

void Index::addPage(int a){
    page.push_back(a);
}

void Index::printPages(){
    cout<<word<<": ";
    for(int i =0; i<page.size();i++){
        cout<<page[i]<<", ";
    }
    cout<<endl;
}

bool Index::findPaperDuplicate(int b){
    for(int i =0; i<page.size(); i++){
        if(page[i] == b){
            return true;
        }
    }
}

Index& Index::operator =(const Index &a){
    word = a.word;
    page.clear();
    for(int i =0; i<a.page.size(); i++){
        page.push_back(a.page[i]);
    }
    return *this;
}
