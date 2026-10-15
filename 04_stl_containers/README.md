# Module 04: STL Containers (vector vs. list)

This module explores standard container mechanics, update/delete performance, memory layout, and the Erase-Remove idiom.

---

## Top Interview Questions & Pro Answers

### Q1: When would you pick `std::vector` over `std::list`?
#### Pro Answer:
> *"In modern CPU architectures, **`std::vector` is the default choice for almost all sequential data needs**. Because its elements are stored contiguously in memory, it offers exceptional **cache locality**, leading to superior traversal and modification performance despite theoretical $O(N)$ insertion costs. `std::list` allocates each node on the heap separately with two pointers, causing cache misses and significant memory overhead (16-24 bytes of pointer overhead per element on 64-bit). Use `std::list` only when you need strict iterator validity guarantees upon insertion/deletion or frequent splicing."*

---

### Q2: What is the C++ Erase-Remove idiom? How did C++20 improve it?
#### Pro Answer:
> *"Before C++20, removing elements matching a value from a `std::vector` required two steps: 
> `v.erase(std::remove(v.begin(), v.end(), val), v.end());` 
> `std::remove` shifts non-matching elements forward and returns the new logical end iterator, while `v.erase` destructs the trailing elements and shrinks the vector size. 
> In **C++20**, this was simplified to a single non-member function: `std::erase(v, val);`."*

---

## Code Example in this Directory

* [`vector_vs_list.cpp`](./vector_vs_list.cpp): Demonstrates value updates, deletions, and iterator mechanics in `vector` and `list`.
