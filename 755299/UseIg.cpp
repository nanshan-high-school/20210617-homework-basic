//
// Created by Howard_Yu on 2021/6/17.
//

#include <ctime>
#include <cstdlib>
#include "ig.h"

#define BOLDBLUE "\033[1m\033[34m"
#define GREEN "\e[0;32m"
#define RESET "\033[0m"

//Emoji constructor
Emoji::Emoji(std::string faceType) : shape(std::move(faceType)), count(0) {}

//Poster constructor
Poster::Poster() : is_emoji(0), Emoji_arr{Emoji(FACE[0]), Emoji(FACE[1]), Emoji(FACE[2]), Emoji(FACE[3])} {}
Poster::Poster(std::string a[5]) : Emoji_arr{Emoji(FACE[0]), Emoji(FACE[1]), Emoji(FACE[2]), Emoji(FACE[3])} {
  char *ptr;
  this->po_time = strtol(a[0].c_str(), &ptr, 10);
  std::string temp;
  for (const char &i : a[1]) {
    if (i != ' ') {
      temp += i;
    } else {
      this->mention.push_back(temp);
      temp = "";
    }
  }
  this->content = a[2];
  Emoji_arr[0] = strtol(a[3].c_str(), &ptr, 10);
  Emoji_arr[1] = strtol(ptr, &ptr, 10);
  Emoji_arr[2] = strtol(ptr, &ptr, 10);
  Emoji_arr[3] = strtol(ptr, nullptr, 10);
  this->is_emoji = strtol(a[4].c_str(), &ptr, 10);
}

//Emoji overload operator function ++, -- & =
void Emoji::operator++() { this->count++; }

void Emoji::operator--() { this->count--; }

Emoji &Emoji::operator=(int num) {
  this->count = num;
  return *this;
}

void IgServer::operator-=(std::_Deque_iterator<Poster, const Poster &, const Poster *> a) {
  pop(a);
}

//IgServer load and save history function with encryption
std::string IgServer::encryption_history(int func) {
  long long l, m;
  char n;
  std::ifstream file("example.txt", std::ios::in | std::ios::binary);
  l = file.tellg();
  file.seekg(0, std::ios::end);
  m = file.tellg();
  file >> n;
  long long size = m - l - func;
  std::string key{char(size % 13 + 314159 % 13 + 65), char(int(size % 10) + 30), char(int(size + n) % 7 + 58)};
  file.close();
  return key;
}

void IgServer::load_history() {
  std::ifstream filer;
  filer.open("example.txt");
  if (filer.peek() == std::ifstream::traits_type::eof()) {
    std::cout << "this has no history ." << std::endl;
    return;
  }
  int now = 0;
  std::string line[5]{""};
  getline(filer, loginUser);
  while (getline(filer, line[now])) {
    if (now == 4) {
      Poster temp(line);
      push(temp);
      now = 0;
    } else {
      now++;
    }
  }
  filer.close();
  if (line[0] != encryption_history(3)) {
    std::cout << "This example.txt had been broken. Please undo it or delete all the content.";
    abort();
  }
}

void IgServer::save_history() {
  std::ofstream filer;
  filer.open("example.txt");
  filer << loginUser << std::endl;
  for (auto &it : *this) {
    filer << it;
  }
  filer << encryption_history(0);
  filer.close();
}

//Poster & Emoji overloading << (file out) function
std::ofstream &operator<<(std::ofstream &filer, const Poster &a) {
  filer << a.po_time << std::endl;
  for (const std::string &each_mention : a.mention) {
    filer << each_mention << " ";
  }
  filer << std::endl << a.content << std::endl;
  filer << a.Emoji_arr[0] << a.Emoji_arr[1] << a.Emoji_arr[2] << a.Emoji_arr[3] << std::endl;
  filer << a.is_emoji << std::endl;
  return filer;
}

std::ofstream &operator<<(std::ofstream &filer, const Emoji &a) {
  filer << a.count << " ";
  return filer;
}

//IgServer function login
void IgServer::login() {
  std::cout << "Input login account (you don't need password) :";
  std::cin >> this->loginUser;
}

//IgServer & Poster overloading >>(cin)
std::istream &operator>>(std::istream &in, IgServer &a) {
  do {
    std::string flag;
    std::cout << "enter q to quit :";
    std::cin >> flag;
    if (flag == "q") {
      break;
    }
    a.batchInput();
  } while (true);
  return in;
}

void IgServer::batchInput() {
  Poster batchPost;
  std::cin >> batchPost;
  this->PostStack::push(batchPost);
}

std::istream &operator>>(std::istream &in, Poster &a) {
  std::cout << "mention (stop with input '*'):";
  std::string input;
  in >> input;
  while (input != "*") {
    a.mention.push_back(input);
    in >> input;
  }
  a.po_time = time(nullptr);
  std::cout << "content :";
  in.get();
  getline(in, a.content);
  return in;
}

//IgServer, Poster & Emoji overloading << (file out) function
std::ostream &operator<<(std::basic_ostream<char> &out, IgServer &a) {
  std::cout << "瀏覽個人頁面..." << std::endl << std::endl;
  for (auto &it : a) {
    out << a.loginUser << it << std::endl;
  }
  return out;
}

void Better_TO(time_t time) {
  long long left = time, level = 0;
  while (left >= 60 && level < 3) {
    level++;
    left /= 60;
  }
  if (level == 0) {
    std::cout << left << " seconds";
  } else if (level == 1) {
    std::cout << left << "minutes";
  } else if (level == 2) {
    std::cout << left << "hours";
  } else if (level == 3) {
    std::cout << left / 24 << "days";
  }
}

std::ostream &operator<<(std::ostream &outer, const Poster &a) {
  outer << BOLDBLUE << " @";
  for (const auto &tempForOut : a.mention) {
    outer << tempForOut << " ";
  }
  outer << GREEN;
  Better_TO(int(time(nullptr) - a.po_time));
  outer << " ago " << RESET
        << std::endl << std::string(a.content.length(), '-') << std::endl
        << a.content
        << std::endl << std::string(a.content.length(), '-') << std::endl
        << a.Emoji_arr[0] << a.Emoji_arr[1] << a.Emoji_arr[2] << a.Emoji_arr[3] << std::endl;
  return outer;
}

std::ostream &operator<<(std::ostream &out, const Emoji &a) {
  out << a.shape << " " << a.count << "   ";
  return out;
}

//IgServer enter action
void IgServer::reaction() {
  int post_num;
  while (true) {
    system("clear");
    std::cout << *this;
    int act;
    std::cout << "do reaction(0:exit, 1:delete, 2:emoji, 3:add) :";
    std::cin >> act;
    if (!act) {
      break;
    } else if (act == 1) {
      std::cout << "delete(0:exit, 1:first post, ......) :";
      std::cin >> post_num;
      if (!post_num) {
        break;
      } else {
        *this -= (this->begin() + post_num - 1);
      }
    } else if (act == 2) {
      std::cout << "add faces to(0:exit, 1:first post, ......) :";
      std::cin >> post_num;
      if (!post_num) {
        break;
      } else {
        (this->begin() + post_num - 1)->rate();
      }
    } else if (act == 3) {
      std::cin >> *this;
    }

  }
}

//Poster enter user felling
void Poster::rate() {
  int rater;
  std::cout << "input (1:like 2:angry 3:happy 4:cry 5:break) :";
  std::cin >> rater;
  if (rater == 5) {
    return;
  } else if (!is_emoji) {
    ++this->Emoji_arr[rater - 1];
    is_emoji = rater;
  } else if (is_emoji == rater) {
    --this->Emoji_arr[rater - 1];
    is_emoji = 0;
  } else {
    --this->Emoji_arr[is_emoji - 1];
    ++this->Emoji_arr[rater - 1];
    is_emoji = rater;
  }
}

int main() {
  IgServer mainProcess;
  mainProcess.load_history();
  if (!mainProcess.is_login()) {
    mainProcess.login();
  }
  mainProcess.reaction();
  mainProcess.save_history();
}