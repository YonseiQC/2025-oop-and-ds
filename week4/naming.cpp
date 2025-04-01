class MyClass {
private:
	int time;
	int myVariable_;
public:

	void my_function(); // snake_case (Python PEP8)
	void myFunction(); // camelCase
	
	void set_time(int time) {
		(*this).time = time;
		this->time = time;
	}
};

std::vector<int>::const_iterator

// a member function in a class is translated by a compiler as
void set_time(MyClass& ref, int time) {
	// this within a class is the same as ref in current function
}


class MyClass1 {
};

class YourClass {
}
