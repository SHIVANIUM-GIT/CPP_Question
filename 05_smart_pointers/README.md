# Module 05: Smart Pointers & Memory Management

This module explores modern C++ memory ownership with `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`.

---

## 🔥 Top Interview Questions & Pro Answers

### Q1: Why should you prefer `std::make_unique` and `std::make_shared` over raw `new`?
#### 🎙️ Pro Answer:
> *"1. **Exception Safety:** Passing `func(std::shared_ptr<T>(new T()), otherFunc())` can leak memory if `otherFunc()` throws an exception before the smart pointer constructor finishes. `std::make_shared` guarantees atomic creation.*  
>*2. **Memory Efficiency (`make_shared`):** Using `new` requires two separate heap allocations: one for the object `T` and one for the internal control block (ref counts). `std::make_shared` performs **a single combined heap allocation** for both, enhancing cache locality and reducing heap fragmentation.*  
>*3. **Cleaner Syntax:** Eliminates duplicate type specifications (`auto p = std::make_unique<Widget>();`)."*

---

### Q2: How does `std::weak_ptr` resolve Circular References?
#### 🎙️ Pro Answer:
> *"When two objects hold `std::shared_ptr` to each other, their reference counts can never reach 0, creating a **permanent memory leak**. `std::weak_ptr` points to a `shared_ptr` without incrementing its strong reference count. It allows observing the object and can be safely converted to a `shared_ptr` using `.lock()` when access is needed. If the underlying object was destroyed, `.lock()` simply returns `nullptr`."*

---

## 💻 Code Example in this Directory

* [`smart_pointers_demo.cpp`](./smart_pointers_demo.cpp): Demonstrates `unique_ptr` ownership transfer, `shared_ptr` reference counts, and `weak_ptr` break of cyclic leaks.
