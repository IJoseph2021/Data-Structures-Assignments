//Catch system
#define CATCH_CONFIG_RUNNER

//include statements for basic libraries
#include <iostream>
#include "catch.hpp"

//include my custom vector
#include "isaacvector.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <istream>
#include <algorithm>
#include "index.h"


using namespace std;

//function prototypes
void loadIntoVector();
void parse();
void addToVector(string a, int b);
string makeLowerCase(string a);
void sortVector();
void printSortedVector();
int findPageNumber(string  a);
void lineNoBrackets(string a, int b);
void lineWithBrackets(IsaacVector<string> a, int b);
void splitLine(IsaacVector<string>& e, string& f, string g, int n);
void printOut();

//global variables
//This vector will hold the data from each line in the file
IsaacVector <string> hold;
//This vector will hold the word objects
IsaacVector <Index> objects;
ifstream myFile;
ofstream myFile2;


//Catch method to run TDD
int runCatchTests(int agc, char* const argv[]){
    return Catch::Session().run();
}

//main method with command line arguments passed in
int main(int argc, char* argv[])
{
    //if the first argument is "-t" then perform Catch TDD
    if(strcmp (argv[1], "-t") == 0){
        Catch::Session().run();
    }

    //if the first argument is "-r" then run the program
    else if (strcmp (argv[1], "-r") == 0){
        //open the input file
        myFile.open(argv[2]);
        if(myFile.is_open()){
            //While the file is open, dump all the data into the vector
            while(!myFile.eof()){
                loadIntoVector();
            }
        }
        myFile.close();
        //parse the data and sort the vector
        parse();
        sortVector();
        //print out sorted data to the output file
        myFile2.open(argv[3]);
        if(myFile2.is_open()){
            printOut();
        }
        myFile2.close();
        //print to console
        printSortedVector();
        return 0;
    }
    return 0;
}

//reads out data to output file
//the vector is already sorted when this method is called
//So just print out the first character of a group of strings
//If that first character changes, i.e. the words go from starting with a to starting with b, then print out [B]
void printOut(){
    char a = '*';
    for(int i = 1; i<objects.returnSize()-2; i++){
        if(objects[i].getWord()[0] == a){
            myFile2<<objects[i].returnPages()<<endl;
        }
        else{
            a = objects[i].getWord()[0];
            char b = toupper(a);
            myFile2<<"["<<b<<"]"<<endl;
            myFile2<<objects[i].returnPages()<<endl;
        }
    }
}

//iterates through ever char in a string and converts it to lower case
string makeLowerCase(string a){
    string b = "";
    locale c;
    for(int i =0; i<a.length(); i++){
        b = b + tolower(a[i], c);
    }
    return b;
}

//Takes every line of the input file and stores it in the hold vector
void loadIntoVector(){
    string a;
    getline(myFile, a);
    hold.push_back(a);
    cout<<a<<endl;
}

//This is where object of Index class are created and pushed into the vector
//The method takes both a word and page number and makes an object
//But if the object has the same word as another object then the page number is just added to original object
//No new object is created
//Also checks if a word occurs more than once on the same line, and makes sure two duplicate pages are not added
void addToVector(string a, int b){
    for(int i =0; i<objects.returnSize(); i++){
        if(objects[i].getWord() == a){
            if(objects[i].findPaperDuplicate(b) == true ){
                return;
            }
            objects[i].addPage(b);
            return;
        }
    }
    objects.push_back(Index(a, b));
}


//prints out vector to the console
//similar to the printing method above that prints to a separate file
void printSortedVector(){
    char a = '*';
    for(int i = 1; i<objects.returnSize()-2; i++){
        if(objects[i].getWord()[0] == a){
            objects[i].printPages();
        }
        else{
            a = objects[i].getWord()[0];
            char b = toupper(a);
            cout<<"["<<b<<"]"<<endl;
            objects[i].printPages();
        }
    }
}



//This method parses a line that has no bracketed words
//Takes the entire string and analyzes it character by character
//Only accepts words that have characters that are alphabets, digits, apostraphe, or dashes
//each contiguous line of characters that fall in the above categories are considered a word and pushed into the vector along with the page number
void lineNoBrackets(string a, int b){
    for(int j =0; j<a.length();j++){
        string f = "";
        if(isalpha(a[j]) || isdigit(a[j]) || a[j] == '\'' || a[j] == '-'){
            while(isalpha(a[j]) || isdigit(a[j]) || a[j] == '\'' || a[j] == '-'){
                f = f + a[j];
                j++;
            }
            f = makeLowerCase(f);
            addToVector(f, b);
        }
    }
}

//this method analyzes the string that is in the brackets
//this method is similar to the above method
//One difference is that spaces are viable characters to be included in a word along with the other categories
void lineWithBrackets(IsaacVector <string> a, int b){
    for(int i =0; i<a.returnSize(); i++){
        string f = "";
        for(int j =0; j<a[i].length();j++){

            if(isalpha(a[i][j]) || isdigit(a[i][j]) || a[i][j] == '\'' || a[i][j] == '-' || a[i][j] == ' '){
                while(isalpha(a[i][j]) || isdigit(a[i][j]) || a[i][j] == '\'' || a[i][j] == '-' || a[i][j] == ' '){
                    f = f + a[i][j];
                    j++;
                }
                f = makeLowerCase(f);

            }
        }
        a[i] = f;
        a[i] = makeLowerCase(a[i]);
        addToVector(a[i], b);
    }
}

//this determine if the line that is in the hold vector is a page number or a string of data
//if it is a page number then return that number
int findPageNumber(string a){
    string s;
    int x;
    s = a;
    s.erase(remove(s.begin(), s.end(), '<'), s.end());
    s.erase(remove(s.begin(), s.end(), '>'), s.end());
    stringstream number(s);
    number>>x;
    return x;
}

//For a line that has both regular strings and brackets, this method splits that string
//Bracketstring includes the stuff in the brackets
//And everything else is dumped in another string
void splitLine(IsaacVector<string>& e, string& f, string g, int n){
    while(n>0){
        string b;
        string c;
        stringstream convert(g);
        getline(convert, b, '[');
        getline(convert, c, ']' );
        e.push_back(c);
        f = f + b;
        getline(convert, b, '[');
        f = f + b;
        n = n -1;
    }
}

//total sum of implementation of methods describes above
//this where the data is parsed
void parse(){
    //int to hold page number
    int x;
    //iterate through each line of data
    for(int i =0; i<hold.returnSize();i++){
        //if string begins with a '<' then use the findPageNumber method to extract the number
        if(hold[i][0] == '<'){
            x = findPageNumber(hold[i]);
        }
        //if not then see if there are any brackets in the string that need to be accounted for
        else{
            int n =0;
            for(int j =0; j<hold[i].length(); j++){
                if(hold[i][j] == '['){
                    //this number hold number of brackets and therefore number of times the split method needs to be called
                    n++;
                }
            }
            //create a string and a vector to hold the string remnant and bracketed input respectively
            string otherWords ="";
            IsaacVector<string> bracketString;
            //if there are no brackets then use the method that involves no brackets
            if(n==0){
                lineNoBrackets(hold[i], x);
            }
            //if there are brackets then use the split line method the appropriate amount of times
            if(n!= 0){
                splitLine(bracketString, otherWords, hold[i], n);
            }
            //use the methods to parse the bracketed string and get rid of unnecessary symbols
            lineWithBrackets(bracketString, x);
            //also parse the rest of the string
            lineNoBrackets(otherWords, x);
        }
    }
}

//sort the vector using bubble sort
void sortVector(){
    Index temp;
    for(int i =0; i<objects.returnSize()-1; i++){
        for(int j = 1; j<objects.returnSize(); j++){
            //use ASCII table values to sort the string alphabetically
            //The fact that every char has a value in the ASCII table
            if(objects[i].getWord() < objects[j].getWord()){
                temp = objects[i];
                objects[i] = objects[j];
                objects[j] = temp;
            }
        }
    }
}
