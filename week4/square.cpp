class Rectangle {
private:
	double width_;
	double height_;
public:
	Rectangle(double width, double height) : width_(width), height_(height) {
	}

	double area() const {
		return width_ * height_;
	}

	void set_width(double new_width) {
		width_ = new_width;
	}

	void set_height(double new_height) {
		height_ = new_height;
	}
};

class Square : public Rectangle {
public:
	Square(double a) : Rectangle(a, a) {}
};

int main() {
	Rectangle* inst = new Square(3.0);
	inst->set_width(6.0); // not a square anymore
	return 0;
}

// SOLID princple
// Single responsibilty
// Open-Closed
// Liskov substitute principle
// I
// D
