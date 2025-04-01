# Homework 2

### Due Date: April 17th (Thu) 11:59 PM

### Please submit your code to LearnUS 

## Some useful tips 

When giving input using the standard input stream, you can indicate the end of file using Ctrl+D.

To stop the program, press Ctrl+C.


## Problem 1: Implementing your own deque using dynamic array

During the class, we have shown an implementation of dynamic array.
In this problem, we will implement a double-ended queue (deque) using a circular dynamic array.


A possible implementation of deque is maintaining two (periodic) indices for a dynamic array, one for the front and the other for the rear element.
When an element is inserted to the front, we decrease the first index. If it is already 0, we can update it to `capacity-1`.
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


Please submit your code using filename `Deque.hpp`. Please make sure that it **must not** contain `main()`  function. Class `Deque` must be able to be used by C++ code including this `hpp` file.



## Problem 2: Template method pattern

Template method pattern is a design pattern for object oriented programming where the abstract superclass defines a skeleton of the algorithm, but subclasses define their own details of algorithms.

In this problem, we consider a simple code that generates code for defining data class. 



## Problem 3: Polynomial class

