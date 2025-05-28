template<typename K, typename V>
class MyHashMap {
private:
	std::vector<List<std::pair<K, V>>> buckets_;
	std::function<int(Key)> hash_;
public:
	MyHashMap() : buckets_(13) {

	}
	void insert(const K& key, const V& value) {
		buckets_[hash_(key)].append(std::make_pair(key, value));
	}
};
