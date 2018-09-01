#ifndef TWEET_H
#define TWEET_H


class Tweet
{
private:
    int id;
    std::vector <Word> words;
public:
    Tweet();
    void addWord(Word a);
    std::vector<Word> GetCopyOfVector();
};

#endif // TWEET_H
