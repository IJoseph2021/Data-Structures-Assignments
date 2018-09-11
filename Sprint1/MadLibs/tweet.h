#ifndef TWEET_H
#define TWEET_H

#include <string>
#include <vector>
#include "word.h"

class Tweet
{
private:
    std::string id;
    std::vector <Word> words;
    int count;
public:

    Tweet(std::string a);
    Tweet(const Tweet& a);
    std::string getId();
    void setId(std::string a);
    void addWord(Word a);
    std::vector<Word> GetCopyOfVector();
    Word returnLast();
    Word& accessWord(int a);
    int getWordCount();

};

#endif // TWEET_H
