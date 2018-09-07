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
public:
    Tweet(std::string a);
    std::string getId();
    void setId(std::string a);
    void addWord(Word a);
    std::vector<Word> GetCopyOfVector();
    Word returnLast();
};

#endif // TWEET_H
