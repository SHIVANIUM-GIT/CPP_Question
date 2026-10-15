# C++ Senior Interview Preparation Roadmap

Welcome to the **C++ Interview Deep-Dive**. This repository is structured into modular topics with:
1. **Senior / Staff Level Interview Questions & Pro Answers**
2. **Under-the-Hood Mechanics (Memory & Compiler Internals)**
3. **Fully Runnable, Self-Contained `.cpp` Code Examples**

---

## 📂 Repository Structure

| Folder | Topic | Key Concepts |
| :--- | :--- | :--- |
| [📁 `00_operator_overloading_and_streams/`](./00_operator_overloading_and_streams/) | **Streams & Operator Overloading** | `cout` chaining (`*this`), `endl` vs `\n`, namespace safety, `friend operator<<` |
| [📁 `01_virtual_functions/`](./01_virtual_functions/) | **Virtual Functions & Polymorphism** | `vptr`, `vtable`, Virtual Destructors, Pure Virtual (`= 0`), Virtual in Constructors trap |
| [📁 `02_static_and_global/`](./02_static_and_global/) | **Static & Global Variables** | The 4 faces of `static`, `extern`, lifetime vs scope, static members |
| [📁 `03_oop_pillars/`](./03_oop_pillars/) | **The 4 Pillars of OOP** | Encapsulation, Abstraction, Inheritance, Polymorphism in modern C++ |
| [📁 `04_stl_containers/`](./04_stl_containers/) | **STL Containers** | `std::vector` vs `std::list`, update, delete, Erase-Remove idiom, complexities |
| [📁 `05_smart_pointers/`](./05_smart_pointers/) | **Smart Pointers & Memory** | `unique_ptr`, `shared_ptr`, `weak_ptr`, circular dependencies, RAII |
| [📁 `06_null_vs_nullptr/`](./06_null_vs_nullptr/) | **NULL vs. nullptr** | Function overload ambiguity with `0`/`NULL`, `std::nullptr_t` type safety |
| [📁 `07_cpp_standards_evolution/`](./07_cpp_standards_evolution/) | **C++ Standards Evolution** | C++11 (auto, lambdas), C++17 (structured bindings, `string_view`), C++20 (concepts) |

---

## How to Compile & Run Any Example
Navigate to any folder and compile using a modern C++ compiler (`g++ -std=c++17`):

```bash
cd 01_virtual_functions
g++ -std=c++17 01_virtual_basics.cpp -o app && ./app
```
