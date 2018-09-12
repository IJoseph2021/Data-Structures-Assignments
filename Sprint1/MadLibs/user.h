#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "tweet.h"
//Basic structure of program is the program, in main, has a vector of users
//Each user has a vector of tweets


class User
{
private:
    //class attributes
    std::string username;

    //vector of tweets
    std::vector<Tweet> tweets;
public:

    //constructor
    User(std::string a);
    //destructor
    ~User();

    //setters and getters
    std::string getUsername();
    void setUsername(std::string a);
    void addTweet(Tweet a);

    //access tweet by reference
    Tweet& accessTweet(int a);

    //get size of tweeet vector in each object of vector
    int getSizeofVector();
};

#endif // USER_H
