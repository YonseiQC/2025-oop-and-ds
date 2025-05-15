#include <iostream>
#include <vector>

int parent_of(int idx) {
	if(idx == 0) {
		// if root
		return -1;
	}
	return (idx - 1)/2;
}

int main() {
	std::vector<int> tree;
	for(int i = 1; i < 32; i++) {
		tree.push_back(i);
	}

	for(int idx = 27; idx != -1; idx = parent_of(idx)) {
		std::cout << tree[idx] << '\n';
	}

	return 0;
}
