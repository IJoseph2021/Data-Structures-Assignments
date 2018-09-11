#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include "tweet.h"
#include "user.h"
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>


using namespace std;


void createUser(string a);
void createTweet(string a, string b);
void printAll();
ifstream myfile;
ifstream myfile2;
vector<User> users;
vector<string> information;

void parseData();

int main(int argc, char *argv[])
{
    myfile.open(argv[1]);
    string c;
    getline(myfile, c);
    if (myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile, c);
            information.push_back(c);
        }
    }
    else{
        cout << "Unable to open file";
    }
    myfile.close();

    parseData();
    printAll();



    myfile2.open(argv[2]);
    if (myfile2.is_open()){
        while(!myfile2.eof()){
        }
    }
    else{
        cout << "Unable to open Mad libs file";
    }
    return 0;
}

void printAll(){
    for(int i =0; i<users.size(); i++){
        for(int j =0; j<users[i].getSizeofVector(); j++){
            cout<<users[i].getUsername()<<"-"<<users[i].accessTweet(j).getId()<<endl;
            cout<<users[i].accessTweet(j).getWord()<<"-"<<users[i].accessTweet(j).getPOS()<<endl;
        }
    }
}

void createUser(string a){
    for(unsigned int i = 0; i<users.size(); i++){
        if(users[i].getUsername() == a){
            return;
        }
     }
     users.push_back(User(a));
}


void parseData(){
    string id;
    string username;
    string word;
    string partOfSpeech;
    for(unsigned int i = 0; i<information.size(); i++){
        stringstream infoStream(information[i]);
        getline(infoStream, id, ',');
        getline(infoStream, username, ',');
        createUser(username);
        string hold;
        getline(infoStream, hold);
        string hold2;
        stringstream streamHold(hold);
        getline(streamHold, hold2, '[');
        getline(streamHold, hold2, ']');
        string hold3;
        getline(streamHold, hold3);
        int counter = 0;
        for(int i =0; i<hold2.length();i++){

            if((hold2[i] == '(') || (hold2[i] == ')')){
                counter++;
            }
        }
        int loops = 0;
        if(counter%2 == 0){
            loops = counter/2;
        }
        else{
            counter--;
            loops = counter/2 + 1;
        }
        stringstream streamHold2(hold2);
        while(loops!= 0){
            string junk;
            string input1;
            string input2;
            getline(streamHold2, junk, '\'');
            for(int i =0; i<junk.length();i++){
                if(junk[i] == '"'){
                    if(junk[i+1] == '"'){
                        string hold;
                        getline(streamHold2, hold, ',');
                        junk = junk + hold;
                        junk.erase(remove(junk.begin(),junk.end(),','), junk.end());
                        junk.erase(remove(junk.begin(),junk.end(),'('), junk.end());
                        junk.erase(remove(junk.begin(),junk.end(),'('), junk.end());
                        junk.erase(remove(junk.begin(),junk.end(),')'), junk.end());
                        junk.erase(remove(junk.begin(),junk.end(),'\"'), junk.end());
                        input1 = junk;
                        goto label;
                    }
                }
            }
            getline(streamHold2, input1, '\'');
            label:
            getline(streamHold2, junk, '\'');
            getline(streamHold2, input2, '\'');
            for(int i =0; i<users.size();i++){
                if(users[i].getUsername() == username){
                    if(hold3[1] == '0'){
                        users[i].addTweet(Tweet (id, input1, input2, 1, 0));
                    }
                    else{
                        users[i].addTweet(Tweet (id, input1, input2, 0, 1));
                    }
                }
            }

            loops--;
        }
    }
}
