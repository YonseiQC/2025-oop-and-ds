#include <iostream>
#include <vector>
#include <limits>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> ps;
	for(int i = 0; i < n+1; i++) {
		int p;
		std::cin >> p;
		ps.push_back(p);
	}

	std::vector<std::vector<int>> c(n+1);
	for(int i = 0; i <= n; i++) {
		c[i].resize(n+1);
	}
	//c[0-n][0-n]
	for(int i = 0; i <= n; i++) {
		c[i][i] = 0;
	}
	for(int r = 1; r < n; r++) {
		for(int i = 1; i <= (n-r); i++) {
			const int j = i+r;
			int min = std::numeric_limits<int>::max();
			for(int k = i; k <= j-1; k++) {
				int val = c[i][k] + c[k+1][j] + ps[i-1]*ps[k]*ps[j];
				if(min > val) {
					min = val;
				}
			}
			c[i][j] = min;
		}
	}
	std::cout << c[1][n] << '\n';
	return 0;
}
