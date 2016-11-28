#ifndef CPPPC__S03__SPARSE_ARRAY_H__INCLUDED
#define CPPPC__S03__SPARSE_ARRAY_H__INCLUDED

// Might come in handy:
#include <unordered_map>

namespace cpppc {

namespace detail {

  template <class ValueT, class SparseArrayT>
    class sparse_array_proxy_ref;

  template <class ValueT, class SparseArrayT>
    class sparse_array_iterator
  {
    typedef int                                                          index_t;
    typedef sparse_array_iterator<ValueT, SparseArrayT>                   self_t;
    typedef index_t                                              difference_type;
    typedef ValueT                                                    value_type;
    typedef value_type*                                                  pointer;
    SparseArrayT                                          &                _data;
    index_t                                                                 _pos;
  public:

    sparse_array_iterator(std::unordered_map<index_t, SparseArrayT> & data,
			index_t pos=0) : _data(data), _pos(pos) { }

    self_t operator+(int offset)         { return self_t(_data, _pos + offset); }
    sparse_array_proxy_ref<value_type, self_t> operator*() { return _data[_pos];}
  };

  template <class ValueT, class SparseArrayT>
    class sparse_array_proxy_ref
  {
    typedef sparse_array_proxy_ref<ValueT, SparseArrayT>                  self_t;
    typedef int                                                          index_t;
    index_t                                                              _offset;
    SparseArrayT                                             &             _data;

  public:

    sparse_array_proxy_ref(index_t offset, SparseArrayT data) :
    _offset(offset), _data(data) { }

  };

} // namespace detail

 template <class T, std::size_t N>
   class sparse_array
   {
     // Just a suggestion:
     typedef sparse_array<T, N>                                          self_t;
     typedef detail::sparse_array_proxy_ref<T, self_t>          proxy_reference;
     typedef int                                                        index_t;
     typedef sparse_array_proxy_ref<T, self_t>                       value_type;
     typedef const value_type                                  const_value_type;
     typedef value_type*                                                pointer;
     typedef const value_type*                                    const_pointer;
     typedef value_type&                                              reference;
     typedef const value_type&                                  const_reference;
     typedef const_pointer                                       const_iterator;

     std::unordered_map<index_t, T> data;
   public:

     typedef detail::sparse_array_iterator<self_t>   iterator;
     typedef index_t                                 difference_type;

     friend iterator;

   public:
     value_type       operator[](size_t offset){
       return value_type(offset, this);
     }

     const_value_type operator[](size_t offset) const {
       return value_type(offset, this);
     }

     size_t size() {
       return 0;
     }

     self_t & operator=(self_t & o) {
       return *this;
     }

     iterator & begin() {
       return ;
     }
   };

} // namespace cpppc

#endif // CPPPC__S03__SPARSE_ARRAY_H__INCLUDED
