# Homework 4

### Due Date: June 16th (Mon) 11:59 PM

### Please submit your code to LearnUS 

## Some useful tips 

When giving input using the standard input stream, you can indicate the end of file using Ctrl+D.

To stop the program, press Ctrl+C.

## Problem 1: AVL Tree

Implement the AVL tree using the code for [a simple binary tree](../week11/simple_binary_search_tree.cpp).
You also need to implement the `main` function processing the following input:

* Each line starts with a letter followed by a number, e.g., `I 103`.
* The first letter is one of `I`, `D`, `F`.
* When the letter is `I`, insert the number to the AVL tree.
* When the letter is `D`, delete the number in the tree. Do nothing if such a number does not exist in the tree.
* When the letter is `F`, find the nubmer in the tree. If there is such a number, print `FOUND`. Otherwise, print `ABSENT`.
* The number can be any integer number between -1,000,000 and 1,000,000.
* You can assume the same number is not inserted twice unless the former one is deleted.

### Example:

Input:
```
I 4
I 5
I 9
I 6
D 4
F 5
F 4
```

Output:
```
FOUND
ABSENT
```

Sumit your code using name `pr1.cpp`.


## Problem 2: Constructing path from maximum path sum problem

During the course, we have studied a problem named "the maximum path sum in matrix", where we find the maximum sum from $n \times n$ matrix where the allowed path is from $(1,1)$ to $(n,n)$ and each move must be one of going "right" or "down".

By changing [the original code](../week13/max_matrix_path_recursion.cpp), write a program that prints not only the sum but also the path taken. 
The path is a string consists of "R" or "D".
You can print only one path if multiple solutions are available.

### Example:

Input:
```
5
1 1 1 0 1
0 0 1 0 0
0 0 1 1 1
0 0 0 1 0
0 0 0 1 1
```

Output:
```
9
RRDDRDDR
```

Sumit your code using name `pr2.cpp`.

## Notice
We only have two problems in this homework. 
