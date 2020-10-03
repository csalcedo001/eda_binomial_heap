#ifndef BINOMIAL_HEAP_BINOMIAL_HEAP_IPP_
#define BINOMIAL_HEAP_BINOMIAL_HEAP_IPP_

#include "node.hpp"

#include <list>

namespace eda {

namespace binomial_heap {

template <typename T>
int size();

template <typename T>
void BinomialHeap<T>::insert(T value) {
	Node<T> *node = new Node<T>(value);

	this->insert(node);
}

template <typename T>
T get_min();

template <typename T>
void delete_min();

template <typename T>
void decrease_key(Node<T> *, T);

template <typename T>
void BinomialHeap<T>::insert(Node<T> *node) {
	if (node->rank() >= this->nodes_.size()) {
		this->nodes_.resize(node->rank());
	}

	int i = node->rank();
	
	while (i < this->nodes_.size() && this->nodes_[i] != nullptr) {
		node = this->merge(this->nodes_[i], node);
		this->nodes_[i] = nullptr;
	}

	if (i == this->nodes_.size()) {
		this->nodes_.push_back(node);
	}
	else {
		this->nodes_[i] = node;
	}
}

template <typename T>
Node<T> *BinomialHeap<T>::merge(Node<T> *node1, Node<T> *node2) {
	if (node1->value_ < node2->value_) {
		node1->children_.push_back(node2);
		node2->parent_ = node1;

		return node1;
	}
	else {
		node2->children_.push_back(node1);
		node1->parent_ = node2;

		return node2;
	}
}

} // namespace binomial_heap

} // namespace eda

#endif // BINOMIAL_TREE_BINOMIAL_HEAP_IPP_
