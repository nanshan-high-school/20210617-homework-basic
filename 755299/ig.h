//
// Created by Howard_Yu on 2021/6/17.
//

#ifndef INC_20210617_HOMEWORK_BASIC_IG_H
#define INC_20210617_HOMEWORK_BASIC_IG_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "IterableStack.h"

class Emoji {
  std::string shape;
  int count;
 public:
  explicit Emoji(std::string);
  friend std::ostream &operator<<(std::ostream &, const Emoji &);
  friend std::ofstream &operator<<(std::ofstream &, const Emoji &);
  void operator++();
  void operator--();
  Emoji &operator=(int);
};

class Poster {
  time_t now{};
  std::vector<std::string> mention;
  std::string content;
  Emoji Emoji_arr[4];
  int is_emoji;
 public:
  Poster();
  friend std::istream &operator>>(std::istream &, Poster &);
  friend std::ostream &operator<<(std::ostream &, const Poster &);
  friend std::ofstream &operator<<(std::ofstream &, const Poster &);
  void load_post(std::string *);
  void rate();
};

using PostStack = IterableStack<Poster>;

class IgServer : PostStack {
 private:
  std::string loginUser;
  void batchInput();
 public:
  void login();
  friend std::ostream &operator<<(std::basic_ostream<char> &, IgServer &);
  friend std::istream &operator>>(std::basic_istream<char> &, IgServer &);
  void load_history();
  void save_history();
  void reaction();
};

#endif //INC_20210617_HOMEWORK_BASIC_IG_H
