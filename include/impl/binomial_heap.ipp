#ifndef BINOMIAL_HEAP_BINOMIAL_HEAP_IPP_
#define BINOMIAL_HEAP_BINOMIAL_HEAP_IPP_

#include "node.hpp"

#include <list>
#include <iostream>
#include <string>

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
bool BinomialHeap<T>::empty() {
	return this->size_ == 0;
}

template <typename T>
Node<T> *BinomialHeap<T>::insert(T value) {
	Node<T> *node = new Node<T>(value);

	this->insert(node);
	this->size_++;

	if (this->min_ == nullptr || node->value_ < this->min_->value_) {
		this->min_ = node;
	}

	return node;
}

template <typename T>
T BinomialHeap<T>::get_min() {
	// TODO: Throw error when size == 0 
	if (this->size_ == 0) return -1;

	return this->min_->value_;
}

template <typename T>
void BinomialHeap<T>::delete_min() {
	// TODO: Throw error if size is 0
	if (this->size_ == 0) return;

	this->size_--;

	Node<T> *node = this->min_;
	this->nodes_[this->min_->rank()] = nullptr;

	for (auto child : node->children_) {
		this->insert(child);
	}

	delete node;


	if (this->size_ == 0) {
		this->min_ = nullptr;
		return;
	}

	int i = 0;
	
	while (i < this->nodes_.size() && this->nodes_[i] == nullptr) {
		i++;
	}

	Node<T> *min_node = this->nodes_[i];

	for ( ; i < this->nodes_.size(); i++) {
		if (this->nodes_[i] != nullptr && this->nodes_[i]->value_ < min_node->value_) {
			min_node = this->nodes_[i];
		}
	}

	this->min_ = min_node;
}

template <typename T>
void BinomialHeap<T>::decrease_key(Node<T> *node, T value) {
	if (value > node->value_) return;

	node->value_ = value;

	while (node->parent_ != nullptr && node->value_ < node->parent_->value_) {
		std::swap(node->value_, node->parent_->value_);
		node = node->parent_;
	}

	if (value < this->min_->value_) {
		this->min_ = node;
	}
}

template <typename T>
void BinomialHeap<T>::print() {
	for (auto e : this->nodes_) {
		if (e != nullptr) {
			this->print(e, 0);
		}
	}
}

template <typename T>
void BinomialHeap<T>::graph_print() {
	long long name_index = 0x1;

	std::cout << "digraph D {" << std::endl;

	for (auto e : this->nodes_) {
		std::string name = "n";
		name.append(std::to_string(name_index));

		if (e != nullptr) {
			this->graph_print(e, name);
		}

		name_index = name_index << 1;
	}

	std::cout << "}" << std::endl;
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
void BinomialHeap<T>::graph_print(Node<T> *node, std::string name) {
	
	std::cout << "    " << name << " [label=" << node->value_ << "];" << std::endl;
	
	for (int i = 0; i < node->children_.size(); i++) {
		if (node->children_[i] != nullptr) {
			std::string child_name = name;

			child_name.append("_");
			child_name.append(std::to_string(i));

			std::cout << "    " << name << " -> " << child_name << ';' << std::endl;

			this->graph_print(node->children_[i], child_name);
		}
	}
}

template <typename T>
void BinomialHeap<T>::insert(Node<T> *node) {
	node->parent_ = nullptr;

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
