template<int N>
struct Factorial{
	static inline int value = Factorial<N-1>::value;
};

template<>
struct Factorial<0> {
	static inline int value = 1;
};

int main() {
	return Factorial<10>::value;
}
