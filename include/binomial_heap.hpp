#ifndef BINOMIAL_HEAP_BINOMIAL_HEAP_HPP_
#define BINOMIAL_HEAP_BINOMIAL_HEAP_HPP_

#include "node.hpp"

#include <vector>

namespace eda {

namespace binomial_heap {

template <typename T>
class BinomialHeap {
private:
	int size_;
	std::vector<Node<T> *> nodes_;
	Node<T> *min_;

public:
	BinomialHeap();

	int size();
	bool empty();
	Node<T> *insert(T);
	T get_min();
	void delete_min();
	void decrease_key(Node<T> *, T);
	void print();
	void graph_print();

private:
	void print(Node<T> *, int);
	void graph_print(Node<T> *, std::string);
	void insert(Node<T> *);
	Node<T> *merge(Node<T> *, Node<T> *);
};

} // namespace binomial_heap

} // namespace eda

#include "impl/binomial_heap.ipp"

#endif // BINOMIAL_HEAP_BINOMIAL_HEAP_HPP_
