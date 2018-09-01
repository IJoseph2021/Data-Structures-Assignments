#ifndef WORD_H
#define WORD_H
#include <string>

class Word
{
private:
    std::string word;
    std::string POS;
public:
    Word(std::string a, std::string b);
    std::string getWord();
    std::string getPOS();
    void setWord(std::string a);
    void setPOS(std::string b);
};

#endif // WORD_H
