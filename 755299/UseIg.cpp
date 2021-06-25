//
// Created by Howard_Yu on 2021/6/17.
//

#include <ctime>
#include <cstdlib>
#include "ig.h"

#define BOLDBLUE "\033[1m\033[34m"
#define GREEN "\e[0;32m"
#define RESET "\033[0m"

const std::string FACE[4]{u8"\U00002665", u8"\U0001F4A2", u8"\U0001F603", u8"\U0001F622"};

//Emoji constructor
Emoji::Emoji(std::string faceType) : shape(std::move(faceType)), count(0) {}

//Emoji overload operator function ++ & --
void Emoji::operator++() { this->count++; }
void Emoji::operator--() { this->count--; }

//Enter user felling
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

//Poster constructor
Poster::Poster() : is_emoji(0), Emoji_arr{Emoji(FACE[0]), Emoji(FACE[1]), Emoji(FACE[2]), Emoji(FACE[3])} {}

//Emoji overload operator function <<(out)
std::ostream &operator<<(std::ostream &out, const Emoji &a) {
  out << a.shape << " " << a.count << "   ";
  return out;
}

Emoji &Emoji::operator=(int num) {
  this->count = num;
  return *this;
}

//Poster overload operator function >>(in) & <<(out)
std::istream &operator>>(std::istream &in, Poster &a) {
  std::cout << "mention (stop with input '*'):";
  std::string input;
  in >> input;
  while (input != "*") {
    a.mention.push_back(input);
    in >> input;
  }
  a.now = time(nullptr);
  std::cout << "content :";
  in.get();
  getline(in, a.content);
  return in;
}

std::ostream &operator<<(std::ostream &outer, const Poster &a) {
  outer << BOLDBLUE << " @";
  for (const auto &tempForOut : a.mention)
    outer << tempForOut << " ";
  outer << GREEN << (time(nullptr) - a.now) << " second ago " << RESET
        << std::endl << std::string(a.content.length(), '-') << std::endl
        << a.content
        << std::endl << std::string(a.content.length(), '-') << std::endl
        << a.Emoji_arr[0] << a.Emoji_arr[1] << a.Emoji_arr[2] << a.Emoji_arr[3] << std::endl;
  return outer;
}

//Poster and Emoji overload operator function <<(file out)
std::ofstream &operator<<(std::ofstream &file, const Emoji &a) {
  file << a.count << " ";
  return file;
}

std::ofstream &operator<<(std::ofstream &file, const Poster &a) {
  file << a.now << std::endl;
  for (const std::string &each_mention : a.mention) {
    file << each_mention << " ";
  }
  file << std::endl << a.content << std::endl;
  file << a.Emoji_arr[0] << a.Emoji_arr[1] << a.Emoji_arr[2] << a.Emoji_arr[3] << std::endl;
  file << a.is_emoji << std::endl;
  return file;
}

// turn string array to Poser
void Poster::load_post(std::string a[5]) {
  char *ptr;
  this->now = strtol(a[0].c_str(), &ptr, 10);
  int num = 0;
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

//IgServer function login
void IgServer::login() {
  std::cout << "Input login account (you don't need password) :";
  std::cin >> this->loginUser;
}

//IgServer helper function batchInput
void IgServer::batchInput() {
  Poster batchPost;
  std::cin >> batchPost;
  this->PostStack::push(batchPost);
}

//IgServer overload operator function <<(out) & >>(in)
std::ostream &operator<<(std::basic_ostream<char> &out, IgServer &a) {
  for (auto &it : a) {
    out << a.loginUser << it << std::endl;
  }
  return out;
}

std::istream &operator>>(std::basic_istream<char> &in, IgServer &a) {
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

//IgServer function reaction
void IgServer::reaction() {
  int post_num;
  while (true) {
    std::cout << "add faces to(0:exit, 1:first post, ......) :";
    std::cin >> post_num;
    if (!post_num) {
      break;
    } else {
      (this->begin() + post_num - 1)->rate();
    }
    system("clear");
    std::cout << *this;
  }
}

void IgServer::save_history() {
  std::ofstream filer;
  filer.open("example.txt");
  filer << loginUser << std::endl;
  for (auto &it : *this) {
    filer << it;
  }
  filer.close();
}

void IgServer::load_history() {
  std::ifstream filer;
  int now = 0;
  std::string line[5]{""};
  filer.open("example.txt");
  getline(filer, loginUser);
  while (getline(filer, line[now])) {
    if (now == 4) {
      Poster temp;
      temp.load_post(line);
      push(temp);
      now = 0;
    } else {
      now++;
    }
  }
  filer.close();
}

int main() {
  IgServer mainProcess;
  mainProcess.load_history();
  mainProcess.login();
  std::cin >> mainProcess;
  std::cout << mainProcess;
  mainProcess.reaction();
  mainProcess.save_history();
}
