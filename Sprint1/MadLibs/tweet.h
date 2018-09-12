#ifndef TWEET_H
#define TWEET_H
//Header File for tweet class
//include string and vector
#include <string>
#include <vector>

class Tweet
{

//the attributes for tweet are id, word, pos, and sentiment
private:
    std::string id;
    std::string word;
    std::string POS;
    int count;
    int posSentiment;
    int negSentiment;
public:
    //constructor
    Tweet(std::string a, std::string b, std::string c, int d, int e);
    //destructor
    ~Tweet();
    //copy constructor
    Tweet(const Tweet& a);

    //getters and setters for attribute
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
