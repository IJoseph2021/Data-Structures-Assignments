#include "tweet.h"
#include <string>
#include <iostream>
using namespace std;
Tweet::Tweet(string a)
{
    id = a;
}

string Tweet::getId(){
    return id;
}

void Tweet::setId(string a){
    id = a;
}

void Tweet::addWord(Word a){
    words.push_back(a);
}

vector<Word> Tweet::GetCopyOfVector(){
    return words;
}

Word Tweet::returnLast(){
    Word a = words.back();
    return a;
}
