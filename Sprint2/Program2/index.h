#ifndef INDEX_H
#define INDEX_H
#include <vector>
#include <string>

class Index
{
private:
    std::string word;
    std::vector <int> page;
public:
    Index();
    ~Index();
    Index(std::string a);
    Index(std::string a, int b);
    Index& operator = (const Index &a);
    std::string getWord();
    void setWord(std::string a);
    void addPage(int a);
    int accessPage(int a);
    void printPages();
    bool findPaperDuplicate(int b);
};

#endif // INDEX_H
