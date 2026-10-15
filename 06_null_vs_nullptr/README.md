# Module 06: NULL vs. nullptr

This module covers pointer type safety, function overload resolution, and why `nullptr` replaced `NULL` in C++11.

---

## Top Interview Questions & Pro Answers

### Q1: Why was `nullptr` introduced in C++11 to replace `NULL`?
#### Pro Answer:
> *"In C++, `NULL` is typically a preprocessor macro defined as integer `0` (or `0L`). Because it is an integer literal, passing `NULL` to an overloaded function will match the `int` overload instead of the pointer overload, causing subtle logic bugs or compiler ambiguity. 
> `nullptr` is a keyword and a prvalue of type `std::nullptr_t`. It is implicitly convertible only to pointer types and `bool`, but **never to integers**, guaranteeing type safety and unambiguous overload resolution."*

---

### Q2: What is the underlying type of `nullptr`? Can you overload on it?
#### Pro Answer:
> *"The type of `nullptr` is `std::nullptr_t` (defined in `<cstddef>`). Yes, you can write a dedicated function overload that **only** accepts `nullptr`:* 
> ```cpp
> void process(std::nullptr_t) { 
> std::cout << "Explicitly handled null pointer!\n"; 
> }
> ```

---

## Code Example in this Directory

* [`null_vs_nullptr.cpp`](./null_vs_nullptr.cpp): Proves the function overloading bug with `NULL` vs the type-safe behavior with `nullptr`.
