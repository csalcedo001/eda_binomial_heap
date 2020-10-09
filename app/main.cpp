#include <iostream>

#include "binomial_heap.hpp"
#include "node.hpp"

using namespace std;

int main() {
	eda::binomial_heap::BinomialHeap<int> b;

	int n;

	cin >> n;

	int k;

	for (int i = 0; i < n; i++) {
		cin >> k;

		b.insert(k);
	}

	b.print();

	return 0;
}
