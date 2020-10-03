#include <iostream>

#include "binomial_heap.hpp"

using namespace std;

int main() {
	eda::binomial_heap::BinomialHeap<int> b;

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		b.insert(i);
	}

	b.print();

	return 0;
}
