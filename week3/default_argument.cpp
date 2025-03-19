int sum_numbers(int a, int b = 0, int c = 0, int d = 0) {
	return a + b + c + d;
}

int main() {
	sum_numbers(1); // a = 1
	sum_numbers(1, 2); // a = 1, b = 2
	sum_numbers(1, 2, 3); // a = 1, b = 2, c = 3
	sum_numbers(1, 2, 3, 4); // a= 1, b = 2, c = 3, d = 4
	return 0;
}
