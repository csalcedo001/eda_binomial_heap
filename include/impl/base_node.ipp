#ifndef BINOMIAL_HEAP_BASE_NODE_IPP_
#define BINOMIAL_HEAP_BASE_NODE_IPP_

#include "base_node.hpp"

namespace eda {

namespace binomial_heap {

template <typename T, typename Node>
BaseNode<T, Node>::BaseNode() :
	children_(),
	parent_(nullptr)
{ }

template <typename T, typename Node>
BaseNode<T, Node>::BaseNode(T value) :
	children_(),
	parent_(nullptr),
	value_(value)
{ }

template <typename T, typename Node>
int BaseNode<T, Node>::rank() {
	return this->children_.size();
}

} // namespace binomial_heap

} // namespace eda

#endif // BINOMIAL_HEAP_BASE_NODE_IPP_
