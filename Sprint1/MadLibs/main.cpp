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
#include <time.h>
#include <stdlib.h>


using namespace std;


void createUser(string a);
void createTweet(string a, string b);
void printAll();
ifstream myfile;
ifstream myfile2;
ofstream myfile3;
vector<User> users;
vector<string> information;
vector<string> information2;

void parseData();
void parseData2();
void printTypes();
void printUsers();
int main(int argc, char *argv[])
{
    srand(time(NULL));
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
    //printUsers();


    myfile2.open(argv[2]);
    if (myfile2.is_open()){
        while(!myfile2.eof()){
            getline(myfile2, c);
            information2.push_back(c);
        }
    }
    else{
        cout << "Unable to open Mad libs file";
    }
    myfile2.close();
    parseData2();
    myfile3.open(argv[3]);
    if (myfile3.is_open()){
        for(unsigned int i = 0; i<information2.size(); i++){

            myfile3<<information2[i]<<endl;
        }
    }
    myfile3.close();

    return 0;
}

//fix this
void printTypes(){
    vector<string> POS(1);
    int count = 0;
    for(unsigned int i =0; i<users.size(); i++){
        cout<<"yikes"<<endl;
        for(unsigned int j =0; j<users[i].getSizeofVector(); j++){
            for(unsigned int s = 0; s<=POS.size(); s++){
                count = 0;
                if(users[i].accessTweet(j).getPOS() != POS[s]){
                    count++;
               }
                if(count == (POS.size())){
                    POS.push_back(users[i].accessTweet(j).getPOS());
                    goto label;
                }
            }
        label:
        int cool;
        }
   }
    for(unsigned int p =0; p<POS.size(); p++){
        cout<<POS[p]<<endl;
    }
}

void printUsers(){
    for(unsigned int i = 0; i<users.size(); i++){
        cout<<users[i].getUsername()<<endl;
    }
}

void printAll(){
    for(unsigned int i =0; i<users.size(); i++){
        for(unsigned int j =0; j<users[i].getSizeofVector(); j++){
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
        for(unsigned int i =0; i<hold2.length();i++){

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
            for(unsigned int i =0; i<junk.length();i++){
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
            for(unsigned int i =0; i<users.size();i++){
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

void parseData2(){
    string username;
    string hold;
    string sent1;
    string sent2;
    string subIn;
    int counter = 0;
    vector<string> subInVec(0);
    for(unsigned int y=0; y<information2.size()-1;y++){
        stringstream infoStream (information2[y]);
        getline(infoStream, username, ' ');
        getline(infoStream, hold);
       // for(int i =0; i<hold.length();i++){
       //     if(hold[i] == '['){
       //         counter++;
       //     }
       //}
       // vector<string> parsedString (counter+1);
        //vector<string> subIn(counter);
        //int x =0;
        //while(counter!= 0){
        //    stringstream infoStream2 (hold);
        //    getline(infoStream2, parsedString[x], '[');
        //    cout<< parsedString[x]<<":sent"<<endl;
        //    getline(infoStream2, subIn[x], ']');
        //    cout<< subIn[x]<<":fill"<<endl;
        //    if(counter ==1){
        //        x++;
        //        getline(infoStream2, parsedString[x]);
        //        cout<<parsedString[x]<<":sent"<<endl;
        //    }
        //    x++;
        //    counter--;
        //}
        //vector <vector <string>> subIn2(subIn.size());
        //for(int i=0; i<subIn.size();i++){
        //    for(int j =0; j<users.size(); j++){
        //        if(users[j].getUsername() == username){
                    //cout<<users[j].getUsername()<<endl;
         //           for(int k = 0; k<users[j].getSizeofVector(); k++){
          //              if(subIn[i] == users[j].accessTweet(k).getPOS()){
           //                 subIn2[i].push_back((users[j].accessTweet(k).getWord()));
                            //cout<<(users[j].accessTweet(k).getWord())<<endl;
             //           }
               //     }
               // }
           // }
       // }
        stringstream infoStream2 (hold);
        getline(infoStream2, sent1, '[');
        getline(infoStream2, subIn, ']');
        getline(infoStream2, sent2);

        for(unsigned int i =0; i<users.size();i++){
            if(users[i].getUsername() == username){
                cout<<users[i].getUsername()<<endl;
                for(unsigned int j =0; j<users[i].getSizeofVector(); j++){
                    if(subIn == users[i].accessTweet(j).getPOS()){
                        //cout<< users[i].accessTweet(j).getPOS()<<endl;
                        string c = users[i].accessTweet(j).getWord();
                        subInVec.push_back(c);
                        for(int l= 0; l<subInVec.size();l++){
                            cout<<subInVec[l]<<endl;
                        }


                    }
                }
            }
        }
        information2[y] = username + " ";
        information2[y] = information2[y] + sent1;
        int v = 0;//rand()%(subInVec.size());
        cout<<v<<endl;
        cout<<subInVec.size()<<endl;
        subIn = subInVec[v];
        information2[y] = information2[y] + "["+subIn+"]";
        information2[y] = information2[y] + sent2;
        subInVec.clear();
        //for(int i = 0; i<parsedString.size(); i++){
        //    if(i == subIn.size()){
        //        information2[y] = information2[y]  + parsedString[i];
        //    }
        //    else{
        //        information2[y] = information2[y]  + parsedString[i];
        //        int v = rand()%(subIn2[i].size());
        //        subIn[i] = subIn2[i][v];
        //        information2[y] = information2[y]  + "[" +subIn[i] + "]";
        //    }

       // }

    }
}
