# Chapter 2: Data Structures and Libraries

## Linear Data Structures with Built-in Libraries

###### Static Array

* Native in Java and C

Static Array (native support in both C/C++ and Java) This is clearly the most commonly used data structure in programming contests. Whenever there is a collection of sequential data to be stored and later accessed using their indices.

###### Dynamically-Resizeable Array

* C++ STL `vector`

Similar to static array except dynamic in size.

It is better to use a vector in place of an array if the size of the sequence of elements is unknown at compile-time.

Frequent Methods:

* `resize()`
* `assign()`
* `clear()`
* `erase()`


###### Array of Boolians

* C++ STL `bitset`

Works like an array with values `TRUE` and `FALSE`. Provides following methods:

* `set()`: sets the bit to `FALSE`
* `reset()`: sets the bit to `TRUE`
* `test()`: returns the value of the bit

###### Bitmask

* Native in C++ and Java

we can use integers to represent a lightweight small set of Boolean values. All set operations then involve only the bitwise manipulation of the corresponding integer, which makes it a much more efficient choice when compared with the C++ STL `vector<bool>`, `bitset`, or `set<int>` options.

###### Linked List

* C++ STL `list`

Usually avoided in programming contest, because:

* Accessing elements requires `O(n)` time in average. (inefficient)
* Using pointer may cause runtime error

It has some advantages (rarely used!)
* Inserting in `O(1)` time
* Erasing in `O(1)` time

Providing methods:

* `push_back`
* `push_front`
* `insert`
* `erase`

###### Stack

* C++ STL `stack`

* Used in many algorithms such as infix to postfix conversion, finding strongly connected components, graham scan, bracket matching and ... .

* Behavioral like LIFO

Providing Methods:

* `push`
* `empty`
* `pop`
* `top`

###### Queue

* C++ STL `queue`

Used in problems like layering and shortest distance (using BFS).

* Behavioral like FIFO

Providing Methods:

* `push`
* `empty`
* `pop`
* `front`


###### Double Ended Queue

* C++ STL `deque`

fast O(1) insertions and deletions at both the beginning and the end of the deque. This feature is important in certain algorithm, e.g. the Sliding Window algorithm.

* `push_front`
* `pop_front`
* `push_back`
* `pop_back`
* `empty`

### Searching and Sorting

#### Sorting

* `O(n^2)` Comparison based sorts such as: bubble, selection and insertion sort.

> ##### Bubble sort
```
template <class T> void b_sort(vector <T> myvec , bool (*comp)(int , int)){
    for (int i = 0 ; i < myvec.size() ; i++){
        for (int j = 0 ; j < myvec.size() ; j++){
            if (!comp(myvec[j], myvec[j+1])){
                swap (myvec[j] , myvec[j+1]);
            }
        }
    }
    return;
}
```
![](bubble-sort.gif)

> ##### Selection Sort
```
template <class T> void b_sort(vector <T> myvec , bool (*comp)(int , int)){
    for (int i = 0 ; i < myvec.size() ; i++){
        int min_val = MAX_INT;
        int min_index = -1;
        for (int j = i ; j < myvec.size() ; j++){
            if (comp(myvec[j] , min_val))
            {
                min_val = myvec[j];
                min_index = j;
            }
        }
        swap (myvec[i] , myvec[j]);
    }
    return;
}
```
![](selection-sort.gif)

> ##### Insertion Sort
```
template <class T> void b_sort(vector <T> myvec , bool (*comp)(int , int)){
    for (int i = 1 ; i < myvec.size() ; i++){
        int j = i;
        while (comp(myvec[j] , myvec[j - 1])){
            swap(myvec[j] , myvec[j - 1]);
            j--;
        }
    }
    return;
}
```
![](insertion-sort.gif)

#### Searching

* **O(n) Linear Search**: Consider every element from index `0` to index `n − 1`

* **O(log n)** Binary Searching: `lower bound`, `upper bound`, or `binary search` in C++ STL `algorithm`

* **O(1) with Hashing functions**

## Non-Linear Data Structures with Built-in Libraries

#### Balanced Binary Search Tree (BST)

Available as `stl, map` or `stl, set`.

BST is a tree such that items on the left subtree of x are smaller than x and items on the right subtree of x are greater than (or equal to) x.

Organizing the data like this  allows for O(log n) `search(key)`, `insert(key)`, `findMin()/findMax()`, `successor(key)/predecessor(key)`, and `delete(key)`.

the C++ STL map (and Java TreeMap) stores (key → data) pairs whereas the C++ STL set (and Java TreeSet) only stores the key.

#### Heap

Available in `C++ STL priority_queue`.

The (Max) Heap enforces the Heap property: in each subtree rooted at x, items on the left and right subtrees of x are smaller than (or equal to) x.

top (or root) of the heap is always the maximum element. There is no notion of a ‘search’ in the Heap (unlike BSTs). The Heap instead allows for the fast extraction (deletion) of the maximum element: ExtractMax() and insertion of new items: Insert(v)—both of which can be easily achieved by in a O(log n)

Priority Queues are an important component in algorithms like Prim’s (and Kruskal’s) algorithms for the Minimum Spanning Tree (MST) problem , Dijkstra’s algorithm for the Single-Source Shortest Paths (SSSP) problem , and the A* Search algorithm

Also partial sort (heap sort) uses this tree to sort n elements in `O(n log n)`

#### Hash Tables

but we do not recommend using it in programming contests unless absolutely necessary.
