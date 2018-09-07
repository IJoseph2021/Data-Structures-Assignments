#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include "tweet.h"
#include "user.h"
#include "word.h"

using namespace std;

string createUser();

string getId();

void createTweet(string a, string b);


ifstream myfile;
vector<User> users;

int main(int argc, char *argv[])
{
    string initial;
    myfile.open(argv[1]);
    if (myfile.is_open()){
        string c;
        getline(myfile, c);
        string a = getId();
        string b = createUser();
        createTweet(a, b);
        cout<<users[0].getUsername()<<endl;
        cout<<(((users[0]).accessTweet(0)).accessWord(0)).getWord()<<endl;
        cout<<(((users[0]).accessTweet(0)).accessWord(0)).getPOS()<<endl;

    }

    else{
        cout << "Unable to open file";
    }
    myfile.close();
    return 0;
}

string getId(){
    string input;
    getline(myfile, input, ',');
    cout<<input<<endl;
    return input;
}

string createUser(){
    string line;
    getline(myfile, line, ',');
    for(int i = 0; i<users.size(); i++){
        if(users[i].getUsername() == line){
            return line;
        }
    }
     users.push_back(User(line));
     return line;
}

void createTweet(string b, string a){
    string junk;
    string input;
    string input2;
    getline(myfile, junk, '\'');
    cout<<junk<<endl;
    getline(myfile, input, '\'');
    cout<<input<<endl;
    getline(myfile, junk, '\'');
    cout<<junk<<endl;
    getline(myfile, input2, '\'');
    cout<<input2<<endl;
    for(int i =0; i<users.size();i++){
        if(users[i].getUsername() == a){
            cout<<"hi"<<endl;
            (users[i]).addTweet( Tweet (b));
            Word b(input, input2);
            ((users[i]).accessTweet(i)).addWord(b);
        }
    }
}
