//
// Created by Armando Herrera (ID: 20217690) on 10/13/19.
// The priority_queue class is missing search functionality with find, I added that by creating a class that
//  inherits priority_queue, exposes the internal iterators, and created a search function that uses the
//  internal iterators.
//

#ifndef SUPERNPUZZLE_SUPER_QUEUE_H
#define SUPERNPUZZLE_SUPER_QUEUE_H

#include <queue>

template<typename T, typename Container, typename Compare>
class super_queue : public std::priority_queue<T, Container, Compare> {
public:
  typedef typename std::priority_queue<T, Container, Compare>::container_type::const_iterator const_iterator;
  using std::priority_queue<T, Container, Compare>::priority_queue;

  template<typename UnaryPredicate>
  const_iterator find(UnaryPredicate p) const {
    auto first = this->c.cbegin();
    auto last = this->c.cend();
    for (; first != last; ++first) {
      if (p(*first))
        return first;
    }
    return last;
  }

  const_iterator begin() const {
    return this->c.cbegin();
  }

  const_iterator end() const {
    return this->c.cend();
  }
};

#endif //SUPERNPUZZLE_SUPER_QUEUE_H
