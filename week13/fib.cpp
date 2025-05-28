#include <vector>

int main() {
	constexpr int N = 100;
	std::vector<int> fib(N);
	fib[0] = 0;
	fib[1] = 1;
	for(int i = 2; i < N; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	return 0;
}
