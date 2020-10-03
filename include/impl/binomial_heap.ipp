#ifndef BINOMIAL_HEAP_BINOMIAL_HEAP_IPP_
#define BINOMIAL_HEAP_BINOMIAL_HEAP_IPP_

#include "node.hpp"

#include <iostream>
#include <list>

namespace eda {

namespace binomial_heap {

template <typename T>
BinomialHeap<T>::BinomialHeap() :
	size_(0),
	min_(nullptr)
{ }

template <typename T>
int BinomialHeap<T>::size() {
	return this->size_;
}

template <typename T>
void BinomialHeap<T>::insert(T value) {
	Node<T> *node = new Node<T>(value);

	this->insert(node);
	this->size_++;

	if (this->min_ == nullptr || value < this->min_->value_) {
		this->min_ = node;
	}
}

template <typename T>
T BinomialHeap<T>::get_min() {
	// TODO: Throw error when size == 0 
	if (this->size_ == 0) return -1;

	return this->min_->value_;
}

template <typename T>
void BinomialHeap<T>::delete_min() {
	int i = 0;
	Node<T> *node = this->nodes_[0];
	
	for ( ; i < this->nodes_.size() && node == nullptr; i++) {
		node = this->nodes[i];
	}

	int min_value = node->value_;

	for ( ; i < this->nodes_.size(); i++) {
		min_value = std::min(this->nodes_[i]->value_, min_value);
	}

	this->min_ = min_value;
}

template <typename T>
void decrease_key(Node<T> *, T);

template <typename T>
void BinomialHeap<T>::print() {
	for (auto e : this->nodes_) {
		if (e != nullptr) {
			this->print(e, 0);
		}
	}
}

template <typename T>
void BinomialHeap<T>::print(Node<T> *node, int level) {
	int l = level;

	while (l--) {
		std::cout << "    ";
	}
	std::cout << node->value_ << std::endl;

	for (auto e : node->children_) {
		this->print(e, level + 1);
	}
}

template <typename T>
void BinomialHeap<T>::insert(Node<T> *node) {
	if (node->rank() > this->nodes_.size()) {
		this->nodes_.resize(node->rank(), nullptr);
	}

	int i = node->rank();
	
	while (i < this->nodes_.size() && this->nodes_[i] != nullptr) {
		node = this->merge(this->nodes_[i], node);
		this->nodes_[i] = nullptr;

		i++;
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
