//
// Created by Howard_Yu on 2021/6/18.
//

#ifndef INC_20210617_HOMEWORK_BASIC_ITERSTACK_H
#define INC_20210617_HOMEWORK_BASIC_ITERSTACK_H

#include <stack>

template<typename T, typename Container = std::deque<T>>
class IterableStack : public std::stack<T, Container> {
  using std::stack<T, Container>::c;

 public:
  void pop(std::_Deque_iterator<T, const T &, const T *> a) { this->c.erase(a); }
  auto begin() { return std::begin(c); }
  auto end() { return std::end(c); }

  auto begin() const { return std::begin(c); }
  auto end() const { return std::end(c); }
};

#endif //INC_20210617_HOMEWORK_BASIC_ITERSTACK_H
