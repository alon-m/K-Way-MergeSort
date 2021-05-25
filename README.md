# K-Way-MergeSort


Data Structures academy class assignment - to write and implement the k-Way MergeSort algorithm

The algorithm is as follows:

- The algorithm input:
a. Array: array of integers (possibly extended to all variable types with '<', '==', '>' operators)
b. N: amount of elements in Array
c. K: k-way mergesort - merge k arrays
- The algorithm output:
Array of integers (or possibly other types) sorted from lowest to highest

The algorithm:
1) if N < K:
  1.1) sort Array using QuickSort algorithm (implemented in project)
2) else:
  2.1) Split Array to K sub arrays
  2.2) For each of the sub arrays: Run the algorithm (recursively)
  2.3) Merge all arrays to one sorted array
3) return the sorted array


written in C++

classes:
1. IO - responsible for input/output from/to console or files
2. QuickSort - quick sort algorithm
3. MinHeap - a minimum heap implementation
4. HeapNode - a node within the MinHeap
5. KWayMergeSort - the k-way merge sort algorithm

Rules and limitations:
1. Can't use any C++/STL classes (except for string)
2. Must implement all classes used (Heap, HeapNode, etc.)
3. if wrong input was received from user - notify "wrong input" and exit
