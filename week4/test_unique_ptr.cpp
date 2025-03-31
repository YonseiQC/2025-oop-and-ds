#include <memory>
#include <vector>

int main() {
	auto ptr = std::unique_ptr<std::vector<int>>(new std::vector<int>(100, 3));
	auto ptr2 = std::make_unique<std::vector<int>>(100, 3);
}
