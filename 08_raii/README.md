# Module 08: RAII (Resource Acquisition Is Initialization)

RAII is the foundational idiom of modern C++ for leak-free, exception-safe resource management.

---

## Top Interview Questions & Pro Answers

### Q1: What is RAII and why is it so important in C++?
#### Pro Answer:
> *"RAII binds the lifecycle of external resources (heap memory, mutexes, file handles, sockets) to the lifetime of automatic (stack-allocated) objects. The resource is acquired in the constructor and guaranteed to be released in the destructor upon exiting scope. 
> RAII eliminates manual cleanup (`free`, `delete`, `unlock`, `close`) and provides **strong exception safety**: even if an exception unwinds the stack, destructors are guaranteed to run, preventing resource leaks and deadlocks."*

---

### Q2: What was used before RAII and what problems did it cause?
#### Pro Answer:
> *"Before RAII (in C and early C++): 
> 1. Developers relied on manual cleanup (`fclose`, `pthread_mutex_unlock`, `free`). 
> 2. Complex functions with multiple `return` branches led to code duplication (`goto cleanup;` pattern in C). 
> 3. If an exception was thrown before manual cleanup statements were reached, the resource was permanently leaked, often causing deadlocks (unreleased mutexes) or memory exhaustion."*

---

## Code Example in this Directory

* [`raii_demo.cpp`](./raii_demo.cpp): Demonstrates resource leakage without RAII on early return vs. guaranteed cleanup with RAII.
