//
// Created by Howard_Yu on 2021/6/17.
//

#ifndef INC_20210617_HOMEWORK_BASIC_IG_H
#define INC_20210617_HOMEWORK_BASIC_IG_H

#include <iostream>
#include <string>
#include <vector>
#include "IterableStack.h"

class Emoji{
    std::string shape;
    int count;
public:
    explicit Emoji (std::string);
    friend std::ostream & operator <<(std::ostream &, const Emoji &);
    void operator ++();
    void operator --();
};

class Poster{
    std::string name;
    time_t now{};
    std::vector<std::string> at;
    std::string content;
    Emoji like, angry, cry, happy;
    int emojied;
public:
    Poster();
    friend std::istream & operator >> (std::istream &, Poster &);
    friend std::ostream & operator << (std::ostream &, const Poster &);
    void rate();
};

using PostStack=IterableStack<Poster>;

class IgServer : PostStack{
private:
    std::string loginUser;
    void batchInput();
public:
    void login();
    friend std::basic_ostream<char> & operator << (std::basic_ostream<char> &, IgServer &);
    friend std::basic_istream<char> & operator >> (std::basic_istream<char> &, IgServer &);
    void reaction();
};

#endif //INC_20210617_HOMEWORK_BASIC_IG_H
