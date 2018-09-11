#include "user.h"
#include <string>
#include <vector>
using namespace std;

User::User(string a)
{
    username = a;
}

User::~User(){

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


Tweet& User::accessTweet(int a){
    return tweets[a];
}

int User::getSizeofVector(){
    int a = tweets.size();
    return a;
}

