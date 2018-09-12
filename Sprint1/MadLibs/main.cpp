
//Include statements

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


//Function prototypes
void createUser(string a);
void createTweet(string a, string b);
void printAll();
void parseData();
void parseData2();
void printTypes();
void printUsers();
void stats();

//Creating ifstream and ofstream in order to read and write to files
ifstream myfile;
ifstream myfile2;
ofstream myfile3;

//set up global vectors that will hold information
vector<User> users;
//this vector will hold each line of the csv input
vector<string> information;
//this vector wil hold each line of the madlibs input
vector<string> information2;

//main driver that is being passed command line arguemnts for the inpput files
int main(int argc, char *argv[])
{
    //seeding for randomness
    srand(time(NULL));
    //open first file
    myfile.open(argv[1]);
    //clear first line as it is irrelevant to progoram
    string c;
    getline(myfile, c);

    //read in each line and store it in the information vector
    if (myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile, c);
            information.push_back(c);
        }
    }
    //else statements and clost first file
    else{
        cout << "Unable to open file";
    }
    myfile.close();

    //parse data using the information vector
    parseData();
    printAll();
    cout<<endl;
    cout<<endl;

    //open second file and store each line in information2 vector
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

    //close file and parse data
    myfile2.close();
    parseData2();

    //open to third file to be written to
    myfile3.open(argv[3]);
    if (myfile3.is_open()){
        //write the updated  data in the information2 vector to the third vector
        for(unsigned int i = 0; i<information2.size(); i++){

            myfile3<<information2[i]<<endl;
        }
        //also write the words stats to the file
        stats();
    }

    //close file
    myfile3.close();
    return 0;
}

//iterate through each user and print the username
void printUsers(){
    for(unsigned int i = 0; i<users.size(); i++){
        cout<<users[i].getUsername()<<endl;
    }
}

//print ass usernames and associated tweet id's, words, and part of speech
void printAll(){
    for(unsigned int i =0; i<users.size(); i++){
        for(unsigned int j =0; j<users[i].getSizeofVector(); j++){
            cout<<users[i].getUsername()<<"-"<<users[i].accessTweet(j).getId()<<endl;
            cout<<users[i].accessTweet(j).getWord()<<"-"<<users[i].accessTweet(j).getPOS()<<endl;
        }
    }


}

//create the user
//this is done line by line
//so if a user with the same name already exists, exit the function
void createUser(string a){
    for(unsigned int i = 0; i<users.size(); i++){
        if(users[i].getUsername() == a){
            return;
        }
     }
     users.push_back(User(a));
}


//main parseing of the firt input file
void parseData(){
    //local holders
    string id;
    string username;
    string word;
    string partOfSpeech;
    //iterate through each element in the information vector and parse it
    for(unsigned int i = 0; i<information.size(); i++){
        stringstream infoStream(information[i]);

        //extract the id and username, and create the user
        getline(infoStream, id, ',');
        getline(infoStream, username, ',');
        createUser(username);

        //edit the string using get line so that the line in the information vector is of this form  [(word), (pos) ......]
        //makes it easier to extract data
        string hold;
        getline(infoStream, hold);
        string hold2;
        stringstream streamHold(hold);
        getline(streamHold, hold2, '[');
        getline(streamHold, hold2, ']');

        //hold three contains the endbit of the line- the part aht contains the sentiment
        string hold3;
        getline(streamHold, hold3);
        cout<<hold3<<endl;
        int counter = 0;

        //see how many paranthesses there are to see how many tuples there are
        //if there is an odd number of paranthesis that means a paranthese is part of a tuple

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

        //account for the tuples with double quotes
        stringstream streamHold2(hold2);
        while(loops!= 0){
            string junk;
            string input1;
            string input2;
            getline(streamHold2, junk, '\'');
            //look at each character and if there is an instance of two double quotes then extract that string
            for(unsigned int i =0; i<junk.length();i++){
                if(junk[i] == '"'){
                    if(junk[i+1] == '"'){
                        string hold;
                        getline(streamHold2, hold, ',');
                        junk = junk + hold;
                        //edit the string
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

            //input1 and input2 respetively contain the word and part of speech of the tweet object
            getline(streamHold2, input1, '\'');
            label:
            getline(streamHold2, junk, '\'');
            getline(streamHold2, input2, '\'');

            //check to see what the sentiment was at the end of each line
            //now that we have the sentiment, id, word, and part of speech, we can create tweet object
            for(unsigned int i =0; i<users.size();i++){
                if(users[i].getUsername() == username){
                    if(hold3[2] == '4'){
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


//parse the second file
void parseData2(){
    //string holders
    string username;
    string hold;
    //these two hold the part of the string that you do not have to sub in for
    string sent1;
    string sent2;

    //this string is what you substitute the mad lib for
    string subIn;
    int counter = 0;

    //create a vector to hold all the possible word options
    vector<string> subInVec(0);

    //go through each line of the madlibs file
    for(unsigned int y=0; y<information2.size()-1;y++){
        stringstream infoStream (information2[y]);

        //extract the username in order to get access to the tweet the user would use
        getline(infoStream, username, ' ');
        getline(infoStream, hold);

        stringstream infoStream2 (hold);

        // split the string
        //the part in between the hardbraces is the part we are fillin in
        getline(infoStream2, sent1, '[');
        getline(infoStream2, subIn, ']');
        getline(infoStream2, sent2);

        //when you read in a user, iterate through the user vector, and find that user
        //then iterate through all his tweets and see all the words he could have used for the part of speech that is given
        for(unsigned int i =0; i<users.size();i++){
            if(users[i].getUsername() == username){
                //cout<<users[i].getUsername()<<endl;
                for(unsigned int j =0; j<users[i].getSizeofVector(); j++){
                    if(subIn == users[i].accessTweet(j).getPOS()){
                        string c = users[i].accessTweet(j).getWord();
                        //add that word to the vector
                        subInVec.push_back(c);
                        for(int l= 0; l<subInVec.size();l++){
                            //cout<<subInVec[l]<<endl;
                        }


                    }
                }
            }
        }

        //reassemble the string to output into the file
        information2[y] = username + " ";
        information2[y] = information2[y] + sent1;

        //****************************
        //****************************
        //This is where things started giving me a seg fault
        //the commented out code would randomize the words that come out of this vector and get put into the string that will be substituted into the madlib
        //however it kept seg faulting so i had to hard code it to always just give the first word that is in the vector
        //It is still a word that the user did use in the csv file
        //But it does nto have the randomness i intended
        int v = 0;//rand()%(subInVec.size());
        subIn = subInVec[v];
        information2[y] = information2[y] + "["+subIn+"]";
        information2[y] = information2[y] + sent2;
        subInVec.clear();

    }
}

//stats section
//this is a little incomplete
//i got some really annoying bugs that i could not get rid of
void stats(){
    //variables for tweet count, pos tweet count, average tweet count etc.
    int tweetCount =0;
    int posTweets = 0;
    int negTweets = 0;
    int averagePos = 0;
    int posWords = 0;
    int negWords =0;
    int averageNeg = 0;
    string x;
    string y;
    string z;

    //the number of tweets is simply equal to the number of lines put into the initial vector information
    tweetCount = information.size();

    //the number of positive tweets is just those tweets that ended in a 4
    for(int i=0; i<information.size(); i++){
        if(information[i][information[i].length()-1] == '4'){
            posTweets++;
        }
        //if it does not end in four then it is negative
        else{
            negTweets++;
        }
    }

    //is supposed to print out the number of positive words
    //it first checks if it is positive
    //then sees if it is a valid POS
    for(int i =0; i<users.size(); i++){
        for(int j =0; j<users[i].getSizeofVector(); j++){

            if(users[i].accessTweet(j).returnSentPos() == 1){

                string pos = users[i].accessTweet(j).getPOS();

                if((pos == "ADJECTIVE") || (pos == "ADJECTIVE OR NUMERAL") || (pos == "ADVERB") || (pos == "CONJUNCTION") || (pos == "EXISTENTIAL THERE") || (pos == "FOREIGN WORD") || (pos == "INTERJECTION") || (pos == "NOUN") || (pos == "PREPOSITION OR CONJUNCTION") || (pos == "PRONOUN") || (pos == "TO") || (pos == "VERB") || (pos == "USERNAME") ){
                    posWords++;
                }
            }
        }
    }
    //same thing but negative
    for(int i =0; i<users.size(); i++){
        for(int j =0; j<users[i].getSizeofVector(); j++){
            if(users[i].accessTweet(j).returnSentNeg() == 1){
                string neg = users[i].accessTweet(j).getPOS();
                if((neg == "ADJECTIVE") || (neg == "ADJECTIVE OR NUMERAL") || (neg == "ADVERB") || (neg == "CONJUNCTION") || (neg == "EXISTENTIAL THERE") || (neg == "FOREIGN WORD") || (neg == "INTERJECTION") || (neg == "NOUN") || (neg == "PREPOSITION OR CONJUNCTION") || (neg == "PRONOUN") || (neg == "TO") || (neg == "VERB") || (neg == "USERNAME") ){
                    negWords++;
                }
            }
        }
    }

    //simple print out statements
    myfile3<<endl;
    myfile3<<"Word Stats"<<endl;
    myfile3<<"Total Tweets: "<<tweetCount<<endl;
    myfile3<<"Total Postive Tweets: "<<posTweets<<endl;
    myfile3<<"Total Negative Tweets: "<<negTweets<<endl;
    myfile3<<"Average number of words per positive tweet: "<<(posWords/posTweets)<<endl;
    myfile3<<"Average number of words per negative tweet: "<<(negWords/negTweets)<<endl;

}
