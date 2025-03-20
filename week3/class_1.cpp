
class TestClass {
private:
	int val_; // member variable

public:
	void set_val(int val) { // member function
		val_ = val;
	}
	int get_val() { // member function
		return val_;
	}
};

int main() {
	TestClass c;
	return 0;
}
