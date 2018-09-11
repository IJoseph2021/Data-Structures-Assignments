#include "tweet.h"
#include <string>
#include <iostream>
using namespace std;
Tweet::Tweet(string a)
{
    id = a;
    count = 0;
}

string Tweet::getId(){
    return id;
}

void Tweet::setId(string a){
    id = a;
}

void Tweet::addWord(Word a){
    words.push_back(a);
    count = count + 1;
}

vector<Word> Tweet::GetCopyOfVector(){
    return words;
}

Word Tweet::returnLast(){
    Word a = words.back();
    return a;
}

Word& Tweet::accessWord(int i){
    return words[i];
}

int Tweet::getWordCount(){
    return count;
}

Tweet :: Tweet(const Tweet& a){
    id = a.id;
    count = a.count;
    words = a.words;
}
