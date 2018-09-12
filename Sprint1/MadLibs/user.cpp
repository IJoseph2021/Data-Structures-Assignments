#include "user.h"
#include <string>
#include <vector>
using namespace std;

//constructor
User::User(string a)
{
    username = a;
}

//destructor
User::~User(){

}

//setters and getters
string User::getUsername(){
    return username;
}

void User::setUsername(string a){
    username = a;
}

//method to add tweet object to vector
void User::addTweet(Tweet a){
    tweets.push_back(a);
}


//by reference
Tweet& User::accessTweet(int a){
    return tweets[a];
}

int User::getSizeofVector(){
    int a = tweets.size();
    return a;
}

