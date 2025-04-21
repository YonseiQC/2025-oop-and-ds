#include <iostream>
#include <list>

template<typename T>
class PriorityQueue {
private:
	std::list<T> list_;

public:
	void push(T elt) {
		list_.push_back(elt);
	}

	T top() const {
		if(is_empty()) {
			throw std::range_error("Cannot obtain top element from an empty PriorityQueue");
		}
		auto it = list_.begin();
		T max_elt = *it;
		++it;
		for(;it != list_.end(); ++it) {
			if(max_elt < *it) {
				max_elt = *it;
			}
		}
		return max_elt;
	}
	void pop() {
		if(is_empty()) {
			throw std::range_error("Cannot obtain top element from an empty PriorityQueue");
		}
		auto it = list_.begin();
		auto max_elt_it = it;
		T max_elt = *it;
		++it;
		for(;it != list_.end(); ++it) {
			if(max_elt < *it) {
				max_elt = *it;
				max_elt_it = it;
			}
		}
		list_.erase(max_elt_it);
	}

	bool is_empty() const {
		return list_.empty();
	}
};

int main() {
	PriorityQueue<int> pq;
	pq.push(10);
	pq.push(4);
	pq.push(18);
	pq.push(8);
	pq.push(12);

	while(!pq.is_empty()) {
		std::cout << pq.top() << '\n'; pq.pop();
	}

	return 0;
}
