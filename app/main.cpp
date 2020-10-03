#include <iostream>

#include "binomial_heap.hpp"

using namespace std;

int main() {
	eda::binomial_heap::BinomialHeap<int> b;

	b.insert(1);
	b.insert(2);

	return 0;
}
