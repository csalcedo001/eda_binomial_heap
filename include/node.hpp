#ifndef BINOMIAL_HEAP_NODE_HPP_
#define BINOMIAL_HEAP_NODE_HPP_

#include <vector>

#include "base_node.hpp"

namespace eda {

namespace binomial_heap {

template <typename T>
class Node : public BaseNode<T, Node<T> > {
public:
	Node();
	Node(T);
};

} // namespace binomial_heap

} // namespace eda

#include "impl/node.hpp"

#endif // BINOMIAL_HEAP_NODE_HPP_
