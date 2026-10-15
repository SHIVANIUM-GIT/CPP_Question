# Module 03: The 4 Pillars of OOP

This module breaks down Encapsulation, Abstraction, Inheritance, and Polymorphism in C++.

---

## Top Interview Questions & Pro Answers

### Q1: What is the difference between Abstraction and Encapsulation?
#### Pro Answer:
> *"• **Encapsulation is data hiding and bundling:** It packages data with the methods that operate on it and restricts direct member access using `private`/`protected` to guarantee class invariants.* 
>*• **Abstraction is hiding complexity:** It provides a clean, high-level interface (e.g., pure virtual base classes/APIs) while hiding internal mechanics, so callers focus on **what** an object does rather than **how** it does it."*

---

### Q2: What is the Liskov Substitution Principle (LSP) in C++ inheritance?
#### Pro Answer:
> *"LSP states that objects of a derived class must be substitutable for objects of the base class without altering the correctness of the program. In C++, this means public inheritance must strictly represent an **'Is-A'** relationship. Overridden functions should not violate base class preconditions or postconditions."*

---

## Code Example in this Directory

* [`oop_demo.cpp`](./oop_demo.cpp): A unified bank account system implementing all 4 OOP pillars.
