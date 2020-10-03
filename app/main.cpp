#include <iostream>

#include "binomial_heap.hpp"

using namespace std;

int main() {
	eda::binomial_heap::BinomialHeap<int> b;

	int n;

	cin >> n;

	int value = 0;

	for (int i = 0; i < n; i++) {
		value += i % 2 == 1 ? i : -i;
		b.insert(value);
	}

	b.print();

	while (b.size() > 0) {
		cout << "Minimum value is " << b.get_min() << endl;
		b.delete_min();
	}

	return 0;
}
