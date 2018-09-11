#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "tweet.h"
class User
{
private:
    std::string username;
    std::vector<Tweet> tweets;
public:
    User(std::string a);
    ~User();
    std::string getUsername();
    void setUsername(std::string a);
    void addTweet(Tweet a);
    Tweet& accessTweet(int a);
    int getSizeofVector();
};

#endif // USER_H
