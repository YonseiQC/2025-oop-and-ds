# Midterm Project

## Prerequisites

### MacOS
If you are using MacOS, please run the following commands before proceeding:
```bash
$ brew install wget
$ brew install cmake
```

### WSL Ubuntu
For Ubuntu, running the following commands is sufficient:
```bash
$ sudo apt install cmake
```

## Setup
First, in your work directory, run the following commands in your terminal:
```bash
$ wget https://github.com/YonseiQC/2025-oop-and-ds/raw/refs/heads/main/week8/midterm_project_skeleton.tar
$ tar -xvf midterm_project_skeleton.tar
$ mv midterm_project_skeleton midterm_project_{student_id}
```
where you need to change `{student_id}` to your student ID.

After that, run the following script
```bash
$ cd midterm_project_{student_id}
$ mkdir build && cd build
$ CC=$(which gcc) CXX=$(which g++) cmake ..
$ make
```

This will generate an executable `main` in `build` directory.


## Project description

Students need to submit a short (at most 1.5 page) report explaining the result of the following tasks.

**Be sure to add your name and student ID in the report!**

### Task 1

In this task, we want to compare the performance of `std::vector` and `std::list`.
Insert 10 to 100'000 `int` values to the back of each data structure (using `push_back`) and discuss which one is faster.
Now, insert 10 to 100'000 `int` values to the front of each class (using `push_front`) and discuss which one is faster.
Can you explain the difference between those results?


### Task 2
Here, we want to compare the performance of merge sort and insertion sort.
You can use the code in the class.

We prepare the initial array as follows:

* The array has $n$ elements.
* The array except $k$ continuous elements are already sorted in increasing order ($k \leq n$), where the starting index of this interval is random.
* Those $k$ continuous elements are sorted in decreasing order.

For each $k\in\{8, 16, 32, 64, 128, 256\}$ and $n$ from $64$ to $131,072$ (by a factor of 2), run each sorting algorithm on this array.
Discuss how the results change as $n$ and $k$ change.

### Task 3

Choose a recursion algorithm discussed in the class and make a loop version of it using a stack.
Compare the performance of these implementations. Discuss which one is faster.

_Note:_ There will be bonus points if the recursion algorithm is not [tail-recursive](https://en.wikipedia.org/wiki/Tail_call).


## Submission
Submit your code and report to LearnUs. When submitting, the source code directory must be zip-compressed. In the terminal, you can use
```bash
$ zip midterm_project_{student_id}.zip midterm_project_{student_id}
```

**Please remove `build` directory before compressing to reduce the file size**

## Some tips on plotting

Please plot a graph for the benchmark results. Of course, you can use Excel or a similar program, but I recommend using [matplotlib](https://matplotlib.org/) in Python.
For this purpose, you can first print the output of the benchmark results using [`json` or `csv` format](https://github.com/google/benchmark/blob/main/docs/user_guide.md#output-formats).

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

If you want to save the figure instead of showing it, just change the last line to
```python
plt.savefig('plot.png')
```

## Google benchmark tips
You can find all relevant information in [Google Benchmark User Guide](https://github.com/google/benchmark/blob/main/docs/user_guide.md).

## Additional tips
* If you are using C++20 features, add `set(CXX_STANDARD 20)` to `CMakeLists.txt` just below line 3: `project(2025-OOPDS-Midterm)`.
