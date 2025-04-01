template<typename Iterator, typename T>
auto my_accumulate(Iterator b, Iterator e, T val) -> T {
	for(; b!= e; ++b) {
		val += *b;
	}
	return val;
}
