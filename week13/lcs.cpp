#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string a, b;
	std::cin >> a;
	std::cin >> b;

	const int n = a.size();
	const int m = b.size();
	
	std::vector<std::vector<int>> L(n);
	for(int i = 0; i < n; i++) {
		L[i].resize(m);
	}
	for(int i = 0; i < n; i++) {
		if(a[i] == b[0]) {
			L[i][0] = 1;
		} else {
			L[i][0] = 0;
		}
	}
	for(int j = 0; j < m; j++) {
		if(a[0] == b[j]) {
			L[0][j] = 1;
		} else {
			L[0][j] = 0;
		}
	}

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(a[i] == b[j]) {
				L[i][j] = L[i-1][j-1] + 1;
			} else {
				L[i][j] = std::max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	std::cout << L[n-1][m-1] << '\n';

	return 0;
}
