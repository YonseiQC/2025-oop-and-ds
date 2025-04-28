# Midterm Project

## Setup
First, in your work directory, run the following in your terminal:
```bash
$ wget https://github.com/YonseiQC/2025-oop-and-ds/raw/refs/heads/main/week8/midterm_project_skeleton.tar
$ tar -xvf midterm_project_skeleton.tar
$ mv midterm_project_skeleton midterm_project_{your_name}
```
where you need to change `{your_name}` to your real name.

After that, run the following script
```bash
$ cd midterm_project_{your_name}
$ mkdir build && cd build
$ cmake ..
```

This will generate an executable `main` in `build` directory.


## Project description

Students need to submit a short (at most 1.5 page) report explaining the result of the following tasks.

**Be sure to add your name and student id in the report!**

### Task 1

In this task, we want to compare the performance of `std::vector` and `std::list`.
Insert 10 to 100'000 `int` values to the back of each data structure (using `push_back`) and discuss which one is faster.
Now, insert 10 to 100'000 `int` values to the front of each class (using `push_front`) and discuss which one is faster.
Can you explain the different between those results?


### Task 2
Here, we want to compare the performance of merge sort and insertion sort.
You can use the code used the class.

We prepare the initial array as follows:

* The array has $n$ elements.
* The array except $k$ continuous elements are already sorted in increasing order ($k \leq n$), where the starting index of this interval is random.
* Those $k$ continuous elements are sorted in decreasing order.

For each $k\in\{8, 16, 32, 64, 128, 256\}$ and $n$ from $64$ to $131,072$ (by a factor of 2), run each sorting algorithm on this array.
Discuss that how the results changes as $n$ and $k$ changes.

### Task 3

Choose a recursion algorithm discussed in the class and make a loop version of it using a stack.
Compare the performance of these implementations. Discuss which one is faster.

_Note: _ There will be bonus points if the recursion algorithm is not (tail-recursive)[https://en.wikipedia.org/wiki/Tail_call].


## Some tips on plotting

It would be nice if you could plot a graph for the benchmark results. Of course, you can use Excel or similar program, but I would recommend to use [matplotlib](https://matplotlib.org/) in Python.
For this purpose, you first can print the output of the benchmark results using [`json` or `csv` format](https://github.com/google/benchmark/blob/main/docs/user_guide.md#output-formats).

The result can be further processed within Python using [json](https://docs.python.org/3/library/json.html) or [csv](https://docs.python.org/3/library/csv.html) library.
Using those libraries, you can convert the output data into an array, which can be further plotted using `matplotlib`.

Here is a simple example for drawing a plot using matplotlib.
```python
import matplotlib.pyplot as plt

fig, ax = plt.subplots(1, 1)
ax.bar([1, 2, 3, 4], [4, 5, 6, 7])
plt.show()
```

_Note_: You might install matplotlib and python3.*-tk beforehand using `pip install matplotlib` and `sudo apt install python3.{version}-tk`.

If you want to save the figure instead of showing it, just change to last line to
```python
plt.savefig('plot.png')
```

## Google benchmark tips
You can find all relevant information in [Google Benchmark User Guide](https://github.com/google/benchmark/blob/main/docs/user_guide.md).
