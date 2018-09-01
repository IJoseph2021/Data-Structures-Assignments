#include "word.h"
using namespace std;


Word::Word(string a, string b)
{
    word = a;
    POS = b;
}

\


string Word::getPOS(){
    return POS;
}

string Word::getWord(){
    return word;
}

void Word::setWord(string a){
    word = a;
}

void Word::setPOS(string a){
    POS = a;
}


