#ifndef BINOMIAL_HEAP_NODE_HPP_
#define BINOMIAL_HEAP_NODE_HPP_

namespace eda {

namespace binomial_heap {

template <typename T>
class Node {
public:
	std::vector<Node<T> *> children_;
	T value_;
	Node<T> *parent_;

public:
	Node();
	Node(T);

	int rank();
};

} // namespace binomial_heap

} // namespace eda

#include "impl/node.ipp"

#endif // BINOMIAL_HEAP_NODE_HPP_
