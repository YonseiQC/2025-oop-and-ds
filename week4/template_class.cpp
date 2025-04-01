template <typename T>
class MyClass {
private:
	T value_;

public:
	void set_value(const T& value) {
		value_ = value;
	}
};
