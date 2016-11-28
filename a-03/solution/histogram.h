2#ifndef CPPPC__S03__HISTOGRAM_H__INCLUDED
#define CPPPC__S03__HISTOGRAM_H__INCLUDED

// Some headers you might find useful:
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iterator>


template <class Iter>
inline Iter histogram(Iter first, Iter last) {
    typedef typename std::iterator_traits<Iter>::value_type      value_t;
    typedef typename std::iterator_traits<Iter>::difference_type index_t;

    std::unordered_map<index_t, value_t> m;

    std::for_each(first,last, [&](value_t v){
        m[v]++;
    });

    auto input = first;
    std::for_each(first, last, [&](value_t v) {
        if(m.find(v) != m.end()) {
          *input = m[v];
	  input++;
          m.erase(v);
        }
    });

    return input;
}

#endif // CPPPC__S03__HISTOGRAM_H__INCLUDED
