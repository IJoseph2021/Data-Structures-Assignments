#include "user.h"
#include <string>
#include <vector>
using namespace std;

User::User(string a)
{
    username = a;
}

string User::getUsername(){
    return username;
}

void User::setUsername(string a){
    username = a;
}

void User::addTweet(Tweet a){
    tweets.push_back(a);
}

Tweet User::returnLast(){
    Tweet a = tweets.back();
    return a;
}

Tweet& User::accessTweet(int a){
    return tweets[a];
}

