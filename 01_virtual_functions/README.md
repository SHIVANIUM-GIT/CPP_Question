# Module 01: Virtual Functions & Polymorphism

This module covers everything an interviewer will ask about virtual functions, late binding, and memory layout.

---

## 🔥 Top Interview Questions & Pro Answers

### Q1: Why must a base class destructor be declared `virtual`?
#### 🎙️ Pro Answer:
> *"If a base class destructor is not virtual, deleting a derived object via a base pointer leads to undefined behavior. In practice, the compiler performs static binding and calls only the base class destructor. The derived destructor is skipped, leaking all resources owned by the derived class. Declaring the base destructor `virtual` ensures dynamic dispatch via the `vtable`, destroying the derived object first, followed by the base object."*

---

### Q2: What happens if you call a `virtual` function inside a Constructor or Destructor?
#### 🎙️ Pro Answer:
> *"In C++, virtual dispatch is **disabled** during construction and destruction. When inside a Base constructor, the Derived part of the object has not yet been initialized; its `vptr` points to the Base class `vtable`. Calling a virtual function will execute the **Base class version**, NOT the Derived override. In a destructor, the Derived part has already been destroyed, so dynamic dispatch falls back to the Base version as well. If the function is pure virtual, it will crash at runtime with a `pure virtual method called` error."*

---

### Q3: What is the overhead of a `virtual` function?
#### 🎙️ Pro Answer:
> *"1. **Memory Overhead:** Every object gains an 8-byte (on 64-bit systems) `vptr` pointing to the class's `vtable`. Each class with virtual functions has one `vtable` in static memory.*  
>*2. **Runtime Overhead:** Virtual calls require an extra pointer indirection (`ptr->vptr[index]()`) instead of a direct instruction jump.*  
>*3. **Compiler Optimization Overhead:** Virtual functions generally cannot be inlined when called via pointers/references, preventing optimizations like loop unrolling and constant folding."*

---

### Q4: Can a constructor be `virtual`? Can a `static` method be `virtual`?
#### 🎙️ Pro Answer:
> *"**Neither can be virtual.***  
>*• A constructor cannot be virtual because an object must be instantiated before its `vptr` is populated. Furthermore, at construction time, the exact type is already known.*  
>*• A `static` function belongs to the class, not an instance. It lacks a `this` pointer and therefore cannot access an object's `vptr` to resolve dynamic dispatch."*

---

### Q5: What is Object Slicing?
#### 🎙️ Pro Answer:
> *"Object slicing occurs when a derived class object is assigned or passed to a base class variable **by value** rather than by pointer or reference. The derived-specific member variables and the derived `vtable` pointer are sliced off, leaving only the base sub-object. Polymorphism is lost."*

---

## 💻 Code Examples in this Directory

* [`01_virtual_basics.cpp`](./01_virtual_basics.cpp): Demonstrates static binding without `virtual` vs dynamic binding with `virtual`.
* [`02_virtual_destructor.cpp`](./02_virtual_destructor.cpp): Proves memory leaks caused by non-virtual destructors and how `virtual ~Base()` fixes them.
* [`03_pure_virtual_abstract.cpp`](./03_pure_virtual_abstract.cpp): Demonstrates abstract base classes and pure virtual functions (`= 0`).
* [`04_virtual_in_constructor_trap.cpp`](./04_virtual_in_constructor_trap.cpp): Demonstrates the classic trap of calling a virtual function inside a constructor.
