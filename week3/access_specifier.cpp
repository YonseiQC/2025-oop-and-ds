class MyClass {
private:
	int private_member;
public:
	int public_member;

	void set_private_member() {
		a.private_member = 3;
	}
};

int main() {
	MyClass a;
	a.set_private_member();
	a.public_member = 6;
	return 0;
}
