# Homework 1

### Due Date: March 27th (Thu) 11:59 PM

### Please submit your code to LearnUS 

## Some useful tips 

When giving input using the standard input stream, you can indicate the end of file using Ctrl+D.

To stop the program, press Ctrl+C.


## Problem 1: C implementation of reading a number in English (C)

**Note: You are only allowed to use pure C. I will compile the code using `gcc` (not `g++`)!**

In this problem, you are asked to write a program that takes a number in decimal form as an input and outputs an English sentence which corresponds to the number.

For example, if the program gets `1234`, then the output will be "One thousand two hundred thirty four".
We are going to use the short scale, which is used for American English.
In this scale, the name and the numbers match as follows:

| Name        | Number    |
|-------------|-----------|
| Thousand    | $10^{3}$  |
| Million     | $10^{6}$  |
| Billion     | $10^{9}$  |
| Trillion    | $10^{12}$ |
| Quadrillion | $10^{15}$ |
| Quintillion | $10^{18}$ |
| Sextillion  | $10^{21}$ |
| Septillion  | $10^{24}$ |
| Octillion   | $10^{27}$ |
| Nonillion   | $10^{30}$ |
| Decillion   | $10^{33}$ |
| Undecillion | $10^{36}$ |



Your program must get an input line by line from the standard input (using `std::cin`) and outputs to standard output (using `std::cout`) for each input.
For example,
```
$ ./your_program
1000
One thousand
2023
Two thousand twenty three
```
where the first and third lines are the input provided by a user, and the second and the last lines are the outputs from your program.

There are also some details you should note:
* The input is a number between 0 to $10^{36}$.
* Do not use hyphen between words. Always use whitespace (' ', U+0020).
* Do not print period ('.') at the end of the line
* The first character of the line must be printed in uppercase.


When submitting your code, make sure that your file name is **pr1.c**.

### Examples
```
11
Eleven
21
Twenty one
12341234
Twelve million three hundred fourty one thousand two hundread thirty four
```


## Problem 2: RHT (C++)

**Submit C++ (not C) code for solving this problem**

We consider simple instructions that modifies the given input array.

* If the instruction is 'R', we reverse the array.
* If the instruction is 'H', we remove the first element of the array.
* If the instruction is 'T', we remove the last element of the array.


The input has two lines. The first line is the integer array and the second line is the instructions.
Again, the input is from the standard input stream (std::cin). For example, running the program using the input
```bash
[1,2,3,4,5]
HRH
```
will output
```
[4,3,2]
```

To ease the evaluation, please do **not** use any space between comma and numbers.
You can also use the following template:
```C++
std::deque<int> parse_input(const std::string& str) {
	std::deque<int> res;

	std::istringstream ss(str);
	
	ss.ignore(1);
	if(ss.peek() == ']') {
		return {};
	}
	char c;
	while(ss) {
		int val;
		ss >> val;
		res.push_back(val);

		ss.get(c);
		if (c == ']') {
			break;
		}
	}

	return res;
}

int main() {
	std::string line;
	std::getline(std::cin, line);

	std::deque<int> arr = parse_input(line);

	// Write your code

	return 0;
}

```

Please submit your code as **pr2.cpp**



## Problem 3: Sorting integer arrays (C++)



**Submit C++ (not C) code for solving this problem**


Write a C++ code that sort the given integer arrays. The sorted arrays should follow:

* The shorter array appears earlier
* If two arrays has the same length, the lexicographic ordering must be used, i.e., an array with the smaller element at each index appears earlier.

For example, for the given input
```
[1,2,3,4]
[3,2,2]
[3,3,2]
```
the program should output
```
[3,2,2]
[3,3,2]
[1,2,3,4]
```
will be given.

Again, do not use any space between comma and numbers for the output. The input (output) is taken from the standard input (output) stream. 
You can also use the `parse_input` function given above.


Please submit your code as **pr3.cpp**


Please consider to use [`std::sort`](https://en.cppreference.com/w/cpp/algorithm/sort) with a custom compare function.
