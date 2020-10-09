# Binomial heap

Implementation of binomial heap. Run `make` to compile `bin/main` and `bin/graph`, the main executables. Both files have the same input format.

## Input

In the first line, the number of elements n to be inserted in the heap is given. In the second line, n integers follow separated by spaces.

## Output

The executable `bin/main` prints a forest to console, while `bin/graph` outputs a graphviz digraph structure which can be used to build and embed a graph of the heap to a PDF file. The following is a shortcut to create a PDF from an input file:

```
./graph.sh
```

Running `graph.sh` requires an input file `docs/graph.in`, which has the same format described in the Input section. The output PDF is saved as `docs/graph.pdf`.
