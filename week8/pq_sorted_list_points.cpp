#include <iostream>
#include <list>
#include <stdexcept>

struct Point {
	double x;
	double y;
};

bool compare_x_first(const Point& p1, const Point& p2) {
	if(p1.x < p2.x) {
		return true;
	} 
	if(p1.x > p2.x) {
		return false;
	}
	if(p1.y < p2.y) {
		return true;
	}
	return false;
}

bool compare_y_first(const Point& p1, const Point& p2) {
	if(p1.y < p2.y) {
		return true;
	} 
	if(p1.y > p2.y) {
		return false;
	}
	if(p1.x < p2.x) {
		return true;
	}
	return false;
}

template<typename T>
class PriorityQueue {
private:
	std::list<T> list_;

public:
	void push(T elt) {
		auto it = list_.cbegin();
		for(;it != list_.cend(); ++it) {
			if(*it < elt) {
				// we want to insert an element just before this element
				break;
			}
		}
		list_.insert(it, elt);
	}

	T top() const {
		if(is_empty()) {
			throw std::range_error("Cannot obtain top element from an empty PriorityQueue");
		}
		return list_.front();
	}
	void pop() {
		if(is_empty()) {
			throw std::range_error("Cannot obtain top element from an empty PriorityQueue");
		}
		return list_.pop_front();
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
