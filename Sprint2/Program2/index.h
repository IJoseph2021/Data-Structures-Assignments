#ifndef INDEX_H
#define INDEX_H

//include statements
#include "isaacvector.h"

#include <string>

//index class
//each object is a word and has a vectorof pages
class Index
{

private:
    std::string word;
    //I had to use the standard vector because for some reason the overloaded assignement operator for this class was just not working
    //And that is a huge problem because my entire sorting algorithm relies on the overlaoded assignement operator
    //I spent hours trying to debug it, but to no avail
    //Please be merciful for this one, I implemented my IsaacVector at least three times in the main.cpp and it works well
    //I just could not get it to work here
    IsaacVector <int> page;
public:
    //Constructor, destructor, copt constructor, overloaded assignment operator
    Index();
    ~Index();
    Index(std::string a);
    Index(std::string a, int b);
    Index& operator = (const Index &a);
    //getters and setters
    std::string getWord();
    void setWord(std::string a);
    //add page to vector
    void addPage(int a);
    int accessPage(int a);
    void printPages();
    //find if a page number is already stores in vector
    bool findPaperDuplicate(int b);
    //return the string that will be printed to the output file
    std::string returnPages();
};

#endif // INDEX_H
