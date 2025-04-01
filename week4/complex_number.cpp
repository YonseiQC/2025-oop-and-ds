#include <iostream>
#include <format>

class Complex {
public:
	double re_;
	double im_;

	Complex(double re, double im) : re_(re), im_(im) {}

	Complex(const Complex& rhs) = default;
	Complex& operator=(const Complex& rhs) = default;
};


Complex operator+(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs.re_ + rhs.re_, lhs.im_ + rhs.im_);
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs.re_ - rhs.re_, lhs.im_ - rhs.im_);
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs.re_ * rhs.re_ - lhs.im_ * rhs.im_, lhs.im_ * rhs.re_ + lhs.re_ * rhs.im_);
}

std::basic_ostream<char>&
operator<<(std::basic_ostream<char>& s, Complex a) {
	s << std::format("{}+{}j", a.re_, a.im_);
	return s;
}


int main() {
	Complex a(3.0, 4.0); // 3.0 + 4.0j
	Complex b(5.0, 2.0); // 5.0 + 2.0j
						 //
	Complex c = a + b;

	std::cout << c << '\n';

	return 0;
}
