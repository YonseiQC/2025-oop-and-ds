#include <stack>
#include <iostream>

int fib(int n) {
	int res = 0;
	std::stack<int> numbers;

	numbers.push(n);

	while(!numbers.empty()) {
		int k = numbers.top();
		numbers.pop();

		if (k <= 1) {
			res += k;
			continue;
		}

		numbers.push(k-1);
		numbers.push(k-2);
	}
	return res;
}

int main() {
	std::cout << fib(10) << '\n';
	return 0;
}
