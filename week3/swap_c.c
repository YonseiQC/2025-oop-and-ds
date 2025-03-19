void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main() {
	int a = 3;
	int b = 5;

	swap(&a, &b);

	// a == 5
	// b == 3
	return 0;
}
