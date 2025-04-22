std::vector<T> arr;
PriorityQueue<T> queue;
for(auto elt: arr) {
	queue.push(elt);
}

arr.resize(0);
while(!queue.is_empty()) {
	auto elt = queue.top(); queue.pop();
	arr.push_back(elt);
}
