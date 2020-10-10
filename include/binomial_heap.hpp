#ifndef BINOMIAL_HEAP_BINOMIAL_HEAP_HPP_
#define BINOMIAL_HEAP_BINOMIAL_HEAP_HPP_

#include <vector>

#include "node.hpp"
#include "base_binomial_heap.hpp"

namespace eda {

namespace binomial_heap {

template <typename T>
class BinomialHeap : public BaseBinomialHeap<T, Node<T> > { };

} // namespace binomial_heap

} // namespace eda

#endif // BINOMIAL_HEAP_BINOMIAL_HEAP_HPP_
