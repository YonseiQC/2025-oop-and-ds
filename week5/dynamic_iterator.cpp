#include <memory>
#include <iostream>
#include <format>

template<typename T>
class Iterable {
public:
	virtual bool has_next() = 0;
	virtual T get_elem() = 0;
	virtual void to_next() = 0;
	virtual ~Iterable() {}
};

template<typename T>
class SinglyLinkedListIterator;

template<typename T>
struct Node {
	T data;
	Node* next;
};

template<typename T>
class SinglyLinkedList {
private:
	Node<T>* head_;
	int size_;
public:
	SinglyLinkedList() {
		head_ = nullptr;
		size_ = 0;
	}

	bool is_empty() const {
		return (head_ == nullptr);
	}

	const std::string front() const {
		return head_->data;
	}

	void pop_front() {
		if(is_empty()) {
			// do nothing if empty
			return ;
		}
		auto ptr = head_;
		head_ = head_->next;
		delete ptr;
		-- size_;
	}

	void push_front(const T& data) {
		auto node = new Node<T>;
		node->data = data;
		node->next = head_;
		head_ = node;
		++ size_;
	}

	std::string get_data(int idx) const {
		Node<T>* ptr = head_;
		while(idx > 0) {
			ptr = ptr->next;
			--idx;
		}
		return ptr->data;
	}

	std::string& insert(int idx, const std::string& elt) {
		if (idx == 0) {
			push_front(elt);
		}
		Node<T>* ptr = head_;
		while(idx > 1) {
			ptr = ptr->next;
			--idx;
		}
		Node<T>* old_next = ptr->next;
		Node<T>* new_node = new Node<T>;
		new_node->data = elt;
		new_node->next = old_next;
		ptr->next = new_node;
		++size_;
		return new_node->data;
	}

	std::unique_ptr<SinglyLinkedListIterator<T>> iterator() {
		return std::unique_ptr<SinglyLinkedListIterator<T>>(new SinglyLinkedListIterator<T>(head_));
	}

	void remove(int idx) {
		if (idx == 0) {
			pop_front();
			return ;
		}
		Node<T>* ptr = head_;
		while(idx > 1) {
			ptr = ptr->next;
			--idx;
		}

		auto node_to_remove = ptr->next;
		ptr->next = ptr->next->next;
		delete node_to_remove;
		--size_;
	}

	int length() const {
		return size_;
	}

	~SinglyLinkedList() {
		while(!is_empty()) {
			pop_front();
		}
	}
};

template<typename T>
class SinglyLinkedListIterator: public Iterable<T> {
private:
	Node<T>* curr_node_;
public:
	SinglyLinkedListIterator(Node<T>* curr_node)
		: curr_node_(curr_node) {}
	bool has_next() override {
		return curr_node_->next != nullptr;
	}
	T get_elem() override {
		return curr_node_->data;
	}
	void to_next() override {
		curr_node_ = curr_node_->next;
	}
};

template <typename T>
class ArrayIterator : public Iterable<T> {
private:
	T* begin_;
	T* curr_;
	T* end_;
public:
	ArrayIterator(T* begin, int length) {
		begin_ = begin;
		curr_ = begin;
		end_ = begin + length;
	}

	bool has_next() override {
		return !(curr_ == end_);
	}

	T get_elem() override {
		return *curr_;
	}

	void to_next() override {
		++curr_;
	}

	~ArrayIterator() = default;
};

template<typename T>
T accumulate(Iterable<T>& it, T init_val) {
	while(it.has_next()) {
		init_val += it.get_elem();
		it.to_next();
	}
	return init_val;
}

int main() {
	/*
	int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	std::unique_ptr<Iterable<int>> it =
		std::make_unique<ArrayIterator<int>>((int*)arr, 8);
	*/

	SinglyLinkedList<std::string> list;
	for(int i = 0; i< 10; i++) {
		list.push_front(std::format("{}-th element is added", i));
	}
	std::unique_ptr<SinglyLinkedListIterator<std::string>> it = list.iterator();

	while(it->has_next()) {
		std::cout << it->get_elem() << '\n';
		it->to_next();
	}
	// In comparision
	/* For static polymorphism
	 * for (it = std::beign(arr); it != std::end(arr); ++it) {
	 * }
	 */
	
	std::unique_ptr<Iterable<std::string>> iter = list.iterator();

	std::cout << std::format("Sum is {}\n", accumulate(*iter, std::string()));

	return 0;
}
