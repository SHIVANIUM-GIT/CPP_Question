# Module 07: C++ Standards Evolution (C++11, C++17, C++20)

This module summarizes the major paradigm shifts across modern C++ standards.

---

## Top Interview Questions & Pro Answers

### Q1: What are the three most important features of C++11?
#### Pro Answer:
> *"1. **Move Semantics & Rvalue References (`T&&`):** Eliminated deep copies for temporary objects, unlocking massive performance gains in standard containers via `std::move`.* 
>*2. **Smart Pointers (`unique_ptr`, `shared_ptr`):** Standardized modern RAII memory management, virtually eliminating raw `delete`.* 
>*3. **Concurrency Support:** Added native multi-threading primitives (`std::thread`, `std::mutex`, `std::atomic`) directly into the standard library."*

---

### Q2: What major features did C++17 bring to eliminate boilerplate?
#### Pro Answer:
> *"1. **Structured Binding:** Unpacking tuples, pairs, or structs into named variables (`auto [key, val] = my_pair;`).* 
>*2. **`std::string_view`:** Non-owning string reference that eliminates heap allocations for read-only substring operations.* 
>*3. **`std::optional` / `std::variant`:** Type-safe ways to represent nullable returns and tagged unions without raw pointers.* 
>*4. **`if` with initializer:** Scoping variables directly inside the conditional (`if (auto it = m.find(k); it != m.end())`)."*

---

### Q3: What are the 'Big Four' features of C++20?
#### Pro Answer:
> *"1. **Concepts:** Compile-time validation of template parameters (`template<std::integral T>`), delivering readable compiler error messages.* 
>*2. **Ranges:** Composable, lazy-evaluated data pipelines using the pipe operator (`vec | views::filter(...) | views::transform(...)`).* 
>*3. **Coroutines:** Cooperative multitasking via functions that can suspend execution and resume later (`co_await`, `co_yield`, `co_return`).* 
>*4. **Modules:** Replacing `#include` with `import std;`, drastically improving build times and avoiding header pollution."*

---

## Code Example in this Directory

* [`standards_demo.cpp`](./standards_demo.cpp): Demonstrates C++11 lambdas, C++17 structured bindings & `string_view`, and C++20 concepts syntax.
