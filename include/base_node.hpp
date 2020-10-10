#ifndef BINOMIAL_HEAP_BASE_NODE_HPP_
#define BINOMIAL_HEAP_BASE_NODE_HPP_

namespace eda {

namespace binomial_heap {

template <typename T, typename Node>
class BaseNode {
public:
	std::vector<Node *> children_;
	T value_;
	Node *parent_;

public:
	BaseNode();
	BaseNode(T);

	int rank();
};

} // namespace binomial_heap

} // namespace eda

#include "impl/base_node.ipp"

#endif // BINOMIAL_HEAP_BASE_NODE_HPP_
