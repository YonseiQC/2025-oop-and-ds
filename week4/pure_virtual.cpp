class Test {
public:
	virtual ~Test() = 0;
};

class SubTest : public Test {
public:
	~SubTest() override {
	}
};
int main() {
	// All the following instantiations do not work
	SubTest t;
	SubTest* y = new SubTest;
	return 0;
}
