//
// Created by aherrera on 10/13/19.
//

#ifndef SUPERNPUZZLE_SUPER_QUEUE_H
#define SUPERNPUZZLE_SUPER_QUEUE_H

#include <queue>

template<typename T, typename Container = std::vector<T>, typename Compare = std::less<typename Container::value_type>>
class super_queue : public std::priority_queue<T, Container, Compare> {
public:
  typedef typename std::priority_queue<T, Container, Compare>::container_type::const_iterator const_iterator;
  using std::priority_queue<T, Container, Compare>::priority_queue;

  template<typename UnaryPredicate>
  const_iterator find(UnaryPredicate p) {
    auto first = this->c.cbegin();
    auto last = this->c.cend();
    for (; first != last; ++first) {
      if (p(*first))
        return first;
    }
    return last;
  }

  const_iterator begin() {
    return this->c.cbegin();
  }

  const_iterator end() {
    return this->c.cend();
  }
};

#endif //SUPERNPUZZLE_SUPER_QUEUE_H
