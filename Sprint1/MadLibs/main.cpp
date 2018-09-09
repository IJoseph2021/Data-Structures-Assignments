#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tweet.h"
#include "user.h"
#include "word.h"
#include <cctype>
#include <stdio.h>
#include <string.h>


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
    string c;
    getline(myfile, c);
    if (myfile.is_open()){
        while(!myfile.eof()){
        string a = getId();
        string b = createUser();
        createTweet(a, b);
        cout<<"tweet created"<<endl;

    }
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
    string sent;
    bool check = false;
    vector<char*> temp(400);
    int x =0;
    int y =1;
    getline(myfile, junk, '\'');
    getline(myfile, input, '\'');
    while(check == false){
        getline(myfile, junk, ',');
        cout<<junk<<endl;
        (temp[x])= new char[junk.length()+1];
        strcpy(temp[x], junk.c_str());
        for(int i = 0; i<(sizeof(temp[x])/sizeof(temp[x][0])); i++){
            if(temp[x][i] == '"'){
                cout<<"hi"<<endl;
                check = true;
                getline(myfile, sent);
                cout<<sent<<endl;
                goto label;
            }
        }
        x++;
        getline(myfile, junk, '\'');
        cout<<junk<<endl;
        (temp[x])= new char[junk.length()+1];
        strcpy(temp[x], junk.c_str());
        for(int i = 0; i<(sizeof(temp[x])/sizeof(temp[x][0])); i++){
            if(temp[x][i] == '"'){
                cout<<"hi"<<endl;
                check = true;
                getline(myfile, sent);
                goto label;
            }
        }
        x++;
        if((y%2) == 0){
            getline(myfile, input, '\'');
            cout<<input<<endl;
        }
        else{
            getline(myfile, input2, '\'');
                  cout<<input2<<endl;
        }
        y++;

        for(int i =0; i<users.size();i++){
            if(users[i].getUsername() == a){
                (users[i]).addTweet( Tweet (b));
                Word b(input, input2);
                ((users[i]).accessTweet(i)).addWord(b);
            }
        }
    }
    label:
    cout<<endl;
}
