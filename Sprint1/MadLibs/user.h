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
    std::string getUsername();
    void setUsername(std::string a);
    void addTweet(Tweet a);
    Tweet returnLast();
    Tweet& accessTweet(int a);
};

#endif // USER_H
