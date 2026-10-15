# Module 00: Operator Overloading & Streams (`std::cout`)

This module covers `std::cout` chaining mechanics, stream operator overloading, `std::endl` vs. `'\n'`, and namespace safety.

---

## 🔥 Top Interview Questions & Pro Answers

### Q1: How does `cout << "Hello" << "World" << endl;` work under the hood?
#### 🎙️ Pro Answer:
> *"The bitwise left-shift operator `<<` is overloaded for stream insertion. It has **left-to-right associativity**. The expression evaluates as:*  
> `((std::cout.operator<<("Hello")).operator<<("World")).operator<<(std::endl);`  
> *To enable chaining, `operator<<` **returns the stream by reference (`std::ostream&`)**. If it returned `void` or returned by value, subsequent chain calls would fail to compile or create costly stream copies."*

---

### Q2: What is the exact difference between `std::endl` and `'\n'`?
#### 🎙️ Pro Answer:
> *"• `'\n'` simply outputs a newline character into the output buffer.*  
>*• `std::endl` does **two things**: it inserts `'\n'` **AND explicitly calls `stream.flush()`** to force the operating system to flush the buffer to the terminal/file.*  
>*In high-throughput systems or tight loops, using `std::endl` severely degrades performance by causing thousands of unnecessary I/O system calls. **Always prefer `'\n'`** unless an immediate flush is strictly necessary (e.g. before a potential crash). "*

---

### Q3: Why is `using namespace std;` considered bad practice?
#### 🎙️ Pro Answer:
> *"It introduces **namespace pollution**. The `std` namespace contains thousands of names (e.g. `count`, `size`, `sort`, `map`). If you or a third-party library define a function named `count` or `distance`, bringing the entire `std` namespace into scope leads to ambiguous symbol compiler errors.*  
>* **Golden Rule:** Never write `using namespace std;` inside a header file (`.h`/`.hpp`), as it forces that pollution into every file that includes it."*

---

### Q4: Why must `operator<<` for custom classes be overloaded as a non-member (or `friend`) function?
#### 🎙️ Pro Answer:
> *"In a member function binary operator `A.operator+(B)`, the left-hand operand MUST be an object of that class (`A`). For stream insertion (`std::cout << myObj`), the left-hand operand is `std::cout` (`std::ostream`). We cannot modify the standard library's `std::ostream` class to add a member method for our custom class. Therefore, `operator<<` must be declared as a **non-member function** taking `(std::ostream& os, const MyClass& obj)`."*

---

## 💻 Code Example in this Directory

* [`stream_chaining_demo.cpp`](./stream_chaining_demo.cpp): Demonstrates stream chaining with custom `MyCout`, `endl` mechanics, and custom class stream overloading.
