#ifndef TWEET_H
#define TWEET_H

#include <string>
#include <vector>

class Tweet
{
private:
    std::string id;
    std::string word;
    std::string POS;
    int count;
    int posSentiment;
    int negSentiment;
public:

    Tweet(std::string a, std::string b, std::string c, int d, int e);
    ~Tweet();
    Tweet(const Tweet& a);
    std::string getId();
    void setId(std::string a);
    int getWordCount();
    int returnSentPos();
    int returnSentNeg();
    void setSentPos(int a);
    void setSentNeg(int a);
    std::string getWord();
    std::string getPOS();
    void setWord(std::string a);
    void setPOS(std::string a);


};

#endif // TWEET_H
