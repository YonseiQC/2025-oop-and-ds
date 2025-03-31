#include <memory>

struct Node {
	int value;
	std::shared_ptr<Node> next;
};

int main() {
	auto ptr = std::make_shared<Node>();
	ptr->next = std::make_shared<Node>();
	ptr->next->next = ptr;
	return 0;
}
