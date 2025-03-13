#include <vector>
#include <iostream>

int main() {
	std::vector<int> vec{1, 2, 3, 4, 5};
	for(int i = 0; i < 100; i++) {
		vec.push_back(i);
	}
	std::cout << vec[40] << '\n';
	std::cout << vec[80] << '\n';
	std::cout << vec[108] << '\n'; // fast but unsafe
	// std::cout << vec.at(108) << '\n'; // slow but safe
	
	auto it = std::begin(vec);
	std::cout << *it << '\n'; // print 1
	*it = 50;
	std::cout << *it << '\n'; // print 50
	
	auto cit = std::cbegin(vec);
	std::cout << *cit << '\n'; // print 1
	// The following line does not compile
	// *cit = 50; 
	
	auto rit = std::rbegin(vec);
	std::cout << *rit << '\n'; // print 99
	*rit = 50;
	std::cout << *rit << '\n'; // print 50
	
	return 0;
}
