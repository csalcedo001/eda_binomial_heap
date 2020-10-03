#ifndef BINOMIAL_TREE_NODE_HPP_
#define BINOMIAL_TREE_NODE_HPP_

namespace eda {

namespace binomial_tree {

template <typename T>
class Node {
	std::vector<Node<T> *> children_;
	T value_;
	Node<T> *parent_;
};

} // namespace binomial_tree

} // namespace eda

#include "impl/node.hpp"

#endif // BINOMIAL_TREE_NODE_HPP_
