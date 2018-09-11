#include "tweet.h"
#include <string>
#include <iostream>
using namespace std;
Tweet::Tweet(string a, string b, string c, int d, int e)
{
    id = a;
    word =b;
    POS = c;
    count = 0;
    posSentiment = d;
    negSentiment = e;
}

Tweet::~Tweet(){

}

string Tweet::getId(){
    return id;
}

void Tweet::setId(string a){
    id = a;
}


int Tweet::getWordCount(){
    return count;
}

int Tweet::returnSentPos(){
   return posSentiment;
}

int Tweet::returnSentNeg(){
    return negSentiment;
}

void Tweet::setSentNeg(int a){
   negSentiment = a;
}

void Tweet::setSentPos(int a){
    posSentiment = a;
}
Tweet :: Tweet(const Tweet& a){
    id = a.id;
    count = a.count;
    word = a.word;
    POS = a.POS;
}

string Tweet::getWord(){
    return word;
}

string Tweet::getPOS(){
    return POS;
}

void Tweet::setWord(string a){
    word = a;
}

void Tweet::setPOS(string a){
    POS = a;
}

