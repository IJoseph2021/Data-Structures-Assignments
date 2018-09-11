#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include "tweet.h"
#include "user.h"
#include "word.h"
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <algorithm>>


using namespace std;
string createUser();
string getId();
void createTweet(string a, string b);
ifstream myfile;
vector<User> users;
vector<string> information;


int main(int argc, char *argv[])
{
    string initial;
        myfile.open(argv[1]);
        string c;
        getline(myfile, c);
        cout<<c<<endl;
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
        for(int i=0; i<information.size(); i++){
            cout<<information[i]<<endl;
        }
        return 0;


}

