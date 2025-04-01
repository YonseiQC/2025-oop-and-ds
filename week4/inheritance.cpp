#include <iostream>

class Shape {
public:
	virtual void draw() {
		std::cout << "Draw a shape\n";
	}
};

class Circle: public Shape {
public:
	void draw() override {
		std::cout << "Draw a circle\n";
	}
};

class Square : public Shape {
public:
	void draw() override {
		std::cout << "Draw a square\n";
	}
};

int main() {
	Shape* shape = nullptr;
	int k;
	std::cin >> k;
	if (k == 0) {
		shape = new Circle;
	}
	else {
		shape = new Square;
	}
	shape->draw();

	delete shape;
	return 0;
}
