# Midterm Project

## Prerequisite for MacOS
If you are using MacOS, please run the following commands before proceeding:
```bash
$ brew install wget
$ brew install cmake
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

_To be announced_

### Task 2

_To be announced_

### Task 3

_To be announced_


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

If you want to save the figure instead of showing it, just change to last line to
```python
plt.savefig('plot.png')
```

## Google benchmark tips
You can find all relevant information in [Google Benchmark User Guide](https://github.com/google/benchmark/blob/main/docs/user_guide.md).
