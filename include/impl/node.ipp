#ifndef BINOMIAL_HEAP_NODE_IPP_
#define BINOMIAL_HEAP_NODE_IPP_

namespace eda {

namespace binomial_heap {

template <typename T>
Node<T>::Node() :
	children_(),
	parent_(nullptr)
{ }

template <typename T>
Node<T>::Node(T value) :
	children_(),
	parent_(nullptr),
	value_(value)
{ }

template <typename T>
int Node<T>::rank() {
	return this->children_.size();
}

} // namespace binomial_heap

} // namespace eda

#endif // BINOMIAL_HEAP_NODE_IPP_
