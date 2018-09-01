#ifndef WORD_H
#define WORD_H


class Word
{
private:
    std::string word;
    std::string POS;
public:
    Word();
    std::string getWord();
    std::string getPOS();
    void setWord(std::string a);
    void setPOS(std::string b);
};

#endif // WORD_H
