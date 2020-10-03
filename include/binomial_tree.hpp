#ifndef BINOMIAL_TREE_BINOMIAL_TREE_HPP_
#define BINOMIAL_TREE_BINOMIAL_TREE_HPP_

#include "node.hpp"

#include <list>

namespace eda {

namespace binomial_tree {

template <typename T>
class BinomialTree {
private:
	int size_;
	std::list<Node<T> *> first_;

public:
	int size();
	void insert(T);
	T get_min();
	void delete_min();
	void decrease_key(Node<T> *, T);

private:
	void merge();
	void node_merge(Node<T> *, Node<T> *);
};

} // namespace binomial_tree

} // namespace eda

#include "impl/binomial_tree.hpp"

#endif // BINOMIAL_TREE_BINOMIAL_TREE_HPP_
