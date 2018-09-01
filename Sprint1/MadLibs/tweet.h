#ifndef TWEET_H
#define TWEET_H

#include <string>
#include <vector>
#include "word.h"

class Tweet
{
private:
    int id;
    std::vector <Word> words;
public:
    Tweet(int a);
    int getId();
    void setId(int a);
    void addWord(Word a);
    std::vector<Word> GetCopyOfVector();
};

#endif // TWEET_H
