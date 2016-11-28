#ifndef CPPPC__S03__FIND_MEAN_REP_H__INCLUDED
#define CPPPC__S03__FIND_MEAN_REP_H__INCLUDED

// Some headers you might find useful:
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>

namespace cpppc {
template <class Iter>
Iter find_mean_rep(Iter first, Iter last) {
  typedef typename std::iterator_traits<Iter>::value_type value_t;

  if(first == last) {
    return first;
  }

  auto sum  = std::accumulate(first, last, 0);
  auto dist = std::distance(first, last);
  auto med  = sum / dist;

  auto near = std::accumulate(std::next(first),
              last,
              *first,
              [=](value_t prev, value_t cur) {
                if(std::abs(med-prev) < std::abs(med-cur)) {
                  return prev;
                } else {
                  return cur;
                }
              });

  return std::find(first, last, near);
 }
} // Namespace cpppc

#endif // CPPPC__S03__FIND_MEAN_REP_H__INCLUDED
