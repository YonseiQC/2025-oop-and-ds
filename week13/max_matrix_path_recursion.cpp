#include <vector>
#include <iostream>

int max_matrix_path(const std::vector<std::vector<int>>& m, int i, int j) {
	// i >= 1 and j >= 1
	// matrix indices start from 1 
	// m[0][j] == m[i][0] == 0
	if(i == 0 || j == 0) {
		return 0;
	}
	return m[i][j] + std::max(max_matrix_path(m, i-1, j), max_matrix_path(m, i, j-1));
}

int max_matrix_path_dp(const std::vector<std::vector<int>>& m) {
	const int n = m.size() - 1;
	std::vector<std::vector<int>> c(n + 1);
	for(int i = 0; i <= n; i++) {
		c[i].resize(n+1);
	}
	for(int i = 0; i <= n; i++) {
		c[i][0] = 0;
		c[0][i] = 0;
	}
	for(int i =1; i <= n; i++) {
		for(int j =1; j <= n; j++) {
			c[i][j] = m[i][j] + std::max(c[i][j-1], c[i-1][j]);
		}
	}
	return c[n][n];
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> m(n+1);
	for(int i = 0; i <=n; i++) {
		m[i].resize(n+1);
	}
	for(int i = 0; i <=n; i++) {
		m[i][0] = 0;
		m[0][i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			std::cin >> m[i][j];
		}
	}

	std::cout << max_matrix_path(m, n, n) << '\n';
	std::cout << max_matrix_path_dp(m) << '\n';
	return 0;
}
