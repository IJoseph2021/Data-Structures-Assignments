#include "tweet.h"
using namespace std;
Tweet::Tweet(int a)
{
    id = a;
}

int Tweet::getId(){
    return id;
}

void Tweet::setId(int a){
    id = a;
}

void Tweet::addWord(Word a){
    words.push_back(a);
}

vector<Word> Tweet::GetCopyOfVector(){
    return words;
}
