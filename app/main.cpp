#include <iostream>

#include "binomial_heap.hpp"
#include "node.hpp"

using namespace std;

int main() {
	eda::binomial_heap::BinomialHeap<int> b;

	int n;

	cin >> n;

	int value = 0;

	eda::binomial_heap::Node<int> *node = b.insert(100);

	for (int i = 0; i < n; i++) {
		value += i % 2 == 1 ? i : -i;
		b.insert(value);
	}

	b.print();

	b.decrease_key(node, -100);

	b.print();

	while (b.size() > 0) {
		cout << "Size is " << b.size() << " and minimum value " << b.get_min() << endl;
		b.delete_min();
	}

	return 0;
}
