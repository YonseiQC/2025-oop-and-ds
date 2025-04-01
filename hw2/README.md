# Homework 2

### Due Date: April 17th (Thu) 11:59 PM

### Please submit your code to LearnUS 

## Some useful tips 

When giving input using the standard input stream, you can indicate the end of file using Ctrl+D.

To stop the program, press Ctrl+C.


## Problem 1: Implementing your own deque using dynamic array

During the class, we have shown an implementation of dynamic array.
In this problem, we will implement a double-ended queue (deque) using a circular dynamic array for `int` type.


A possible implementation of deque is maintaining two (periodic) indices for a dynamic array, one for the front and the other for the rear element.
When an element is inserted to the front, we decrease the first index. If it is already `0`, we can update it to `capacity-1`.
On the other hand, when an element is pushed to the back, we increase the index for the rear element. If it hits reversed length, it can be updated to `0`.
When two indices met, which is the case we used all the capacity we reserved, we can double the size of array by allocating a new array and copy all elements to a new array.

![Image of a circular array](img/circular_array.svg?raw=true "Circular Array")



Requirements:
* The class name must be `Deque` (the first `D` must be upper-case).
* The class should maintain two indices or pointers for the first and the last elements.
* The class has two member functions: `int& push_back(int val)` and `int& push_front(int val)` where the former (latter) adds elements to the end (front) of the container. Note that these functions return the reference to the added elements.
* The class has two member functions `int front() const` and `int back() const`, which returns the foremost and the rearmost elements (these functions do not change the size of deque).
* The class has two member functions `void pop_front()` and `void pop_back()`, which remove the foremost/rearmost elements. You can assume that the size of deque is at least one when these functions are called.
* Unless resizing is happening, adding elements using `push_back` and `push_front` should be done in constant time.


The filename of your submission must be `Deque.hpp`. Please make sure that it **does not** contain `main()`  function. Class `Deque` must be able to be used by C++ code including this `hpp` file.


You can use the provided [DynamicArray.hpp](./DynamicArray.hpp) file.

## Problem 2: Template method pattern

Template method pattern is a design pattern for object oriented programming where the abstract superclass defines a skeleton of the algorithm, but subclasses define their own details of algorithms.

In this problem, we consider a simple code that generates code for multiple programming languages when the specification of a data class is given.

The data class is defined using the following structure.

```cpp
enum class DataType {INT, FLOAT, STR};

struct ClassDef {
	std::string class_name;
	std::vector<std::pair<DataType, std::string>> variables;
};
```

The first member variable, `class_name` is the name of the data class, and the associated variables are given as `variables`.
Each variable is a pair of the type of variable and the name of variable given in `ALL_CAPS` convention.

For example, we can define a data class for `DriversLicense` as
```cpp
ClassDef my_class;
my_class.class_name = "DriversLicense";
my_class.variables.emplace_back(DataType::STR, "DRIVER_NAME");
my_class.variables.emplace_back(DataType::INT, "DRIVER_AGE");
my_class.variables.emplace_back(DataType::FLOAT, "LEFT_EYE_VISION");
my_class.variables.emplace_back(DataType::FLOAT, "RIGHT_EYE_VISION");
```

This code indicates that we are defining `DriversLicense` class with member names `DRIVER_NAME`, `DRIVER_AGE`, `LEFT_EYE_VISION`, `RIGHT_EYE_VISION` where the type of each variable is STR, INT, FLOAT, FLOAT, respectively.

For this dataclass, we want to have a automatic code generator which outputs the definition of the class for each language.
For example, when we want Java code,
```Java
public class DriversLicense {
    public String driverName;
    public int driverAge;
    public double leftEyeVision;
    public double rightEyeVision;
}
```

Note that `camelCase` is used for each variable name.
Likewise, we may want C++ and Python version of the class as follows:
```Cpp
struct DriversLicense {
    std::string driver_name;
    int driver_age;
    double left_eye_vision;
    double right_eye_vision;
};
```

```Python
class DriversLicense:
    driver_name: str
    driver_age: int
    left_eye_vision: float
    right_eye_vision: float
```
See Python's [dataclass document](https://docs.python.org/3/library/dataclasses.html) for the class definition for Python.


This type of code can be implemented using **template method pattern**.
In [AbstractClassDefPrinter.hpp](./AbstractClassDefPrinter.hpp), we defined `AbtractClassDefPrinter` class that defines 

and [class_def_printer_example.cpp](./class_def_printer_example.cpp) files for a code generating the class definition for Java. 
Following this, write down two classes extending (inheriting) `AbstractClassDefPrinter`, named `PythonClassDefPrinter` and `CppClassDefPrinter`.


For convenience, we summarize the requirement as follows:
* Use `snake_case` for variable names for Python and C++ code generator
* For C++ code, `STR`, `INT`, `FLOAT` translate to `std::string`, `int`, `double`, respectively.
* For Python code, `STR`, `INT`, `FLOAT` translate to `str`, `int`, `float`.


Please submit a single file named `ClassDefPrinter.hpp` which includes the definition of two classes `PythonClassDefPrinter` and `CppClassDefPrinter`.


## Problem 3: Polynomial class
Define a polynomial class which defines a polynomial. Use the following definition
```cpp
class Polynomial {
private:
    std::vector<double> coeffs_;
public:
    explicit Polynomial(const std::vector<double>& coeffs): coeffs_(coeffs) {}
    Polynomial(const Polynomial& ) = default;
    Polynomial& operator=(const Polynomial& rhs) = default;
    // add your code
};
```
where we want to use it as
```cpp
Polynomial p1(std::vector<double>({3.0, 2.0, 5.0})); // p1 = 3.0 + 2.0*x + 5.0*x**2
Polynomial p2(std::vector<double>({1.5, 0.0, 2.0, 3.0})); // p2 = 1.5 + 2.0*x*82 + 3.0*x**3
double v = p1(3.0); // evaluate the polynomial for x=3.0
auto p3 = p1 * p2; // multiplification of two polynomials
```
For this purpose, we want the `Polynomial` class to have the following member functions:
* `double operator(double x) const`
* `Polynomial& operator+=(Polynomial& rhs)`
* `Polynomial& operator-=(Polynomial& rhs)`
* `Polynomial& operator*=(Polynomial& rhs)`


and the following non-member functions:
* `Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs)`
* `Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs)`
* `Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs)`

Please submit your code defining the `Polynomial` class using filename `Polynomial.hpp`
