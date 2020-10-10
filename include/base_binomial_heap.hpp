#ifndef BINOMIAL_HEAP_BASE_BINOMIAL_HEAP_HPP_
#define BINOMIAL_HEAP_BASE_BINOMIAL_HEAP_HPP_

#include "base_node.hpp"

#include <vector>

namespace eda {

namespace binomial_heap {

template <typename T, typename Node>
class BaseBinomialHeap {
protected:
	int size_;
	std::vector<Node *> nodes_;
	Node *min_;

public:
	BaseBinomialHeap();

	int size();
	bool empty();
	Node *insert(T);
	T get_min();
	void delete_min();
	void decrease_key(Node *, T);
	void print();
	void graph_print();

protected:
	void print(Node *, int);
	void graph_print(Node *, std::string);
	void insert(Node *);
	Node *merge(Node *, Node *);
};

} // namespace binomial_heap

} // namespace eda

#include "impl/base_binomial_heap.ipp"

#endif // BINOMIAL_HEAP_BINOMIAL_HEAP_HPP_
