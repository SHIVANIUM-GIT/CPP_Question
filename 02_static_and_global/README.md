# Module 02: Static & Global Variables

This module covers the 4 faces of `static`, global variables, lifetimes, and storage durations.

---

## Top Interview Questions & Pro Answers

### Q1: What are the 4 different uses of the `static` keyword in C++?
#### Pro Answer:
> *"1. **Static Local Variable:** Inside a function, it preserves its state between calls and is initialized only once (thread-safe since C++11).* 
>*2. **Static Member Variable:** Belongs to the class itself, not any instance. Shared across all objects in memory.* 
>*3. **Static Member Function:** Belongs to the class. It lacks a `this` pointer and can only access static members.* 
>*4. **Static at Global/File Scope (Internal Linkage):** Restricts symbol visibility to that specific translation unit (`.cpp` file), hiding it from other files."*

---

### Q2: What is the Static Initialization Order Fiasco? How do you fix it?
#### Pro Answer:
> *"In C++, the initialization order of global static variables in **different translation units** is **undefined**. If global `A` in `fileA.cpp` uses global `B` in `fileB.cpp` during its construction, `B` might still be uninitialized, leading to undefined behavior or crashes.* 
>*The fix is the **Meyers' Singleton pattern** (Construct On First Use): wrap the static variable inside a function returning a reference. Local static variables are guaranteed to initialize the first time the function is called, avoiding order issues."*

---

### Q3: Why can't a `static` member function be `const` or `virtual`?
#### Pro Answer:
> *"• A member function is marked `const` to promise it will not modify `*this`. Since a `static` function has no `this` pointer, marking it `const` is meaningless.* 
>*• A member function is marked `virtual` to allow runtime dynamic dispatch via an object's `vptr`. Since a `static` function belongs to the class and is not called on an object instance, there is no `vptr` to look up."*

---

## Code Examples in this Directory

* [`01_static_local_and_global.cpp`](./01_static_local_and_global.cpp): Global variable vs. local static counter.
* [`02_static_class_members.cpp`](./02_static_class_members.cpp): Static class variable (instance counter) and static utility functions.
