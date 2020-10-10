#ifndef BINOMIAL_HEAP_NODE_IPP_
#define BINOMIAL_HEAP_NODE_IPP_

#include "node.hpp"

#include "base_node.hpp"

namespace eda {

namespace binomial_heap {

template <typename T>
Node<T>::Node() : BaseNode<T, Node<T>>::BaseNode() { }

template <typename T>
Node<T>::Node(T value) : BaseNode<T, Node<T>>::BaseNode(value){ }

} // namespace binomial_heap

} // namespace eda

#endif // BINOMIAL_HEAP_NODE_IPP_
