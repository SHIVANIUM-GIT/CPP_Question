# Module 09: The Producer-Consumer Problem

A comprehensive breakdown of multi-threaded thread synchronization using `std::mutex`, `std::condition_variable`, and RAII locks.

---

## Top Interview Questions & Pro Answers

### Q1: What is the Producer-Consumer problem and how is it solved in modern C++?
#### Pro Answer:
> *"The Producer-Consumer problem models synchronization between threads producing data and threads consuming data through a shared buffer. 
> It is solved using: 
> 1. `std::mutex` to protect concurrent queue access. 
> 2. `std::condition_variable` to suspend threads without busy-waiting (CPU spinning). 
> 3. `std::unique_lock` (RAII) to automatically manage mutex state during `wait()` calls."*

---

### Q2: Why MUST `cv.wait()` be checked inside a `while` loop (or predicate)? What are Spurious Wakeups?
#### Pro Answer:
> *"Operating systems can wake up sleeping threads even if no thread called `notify_one()` or `notify_all()`. This is known as a **Spurious Wakeup**. 
> Additionally, another consumer might wake up first and drain the queue before this thread acquires the mutex. 
> Therefore, you must always check the condition in a loop:* 
> `while (queue.empty()) cv.wait(lock);` 
> *or use the modern C++ predicate overload:* 
> `cv.wait(lock, [&]() { return !queue.empty(); });`"

---

## Code Example in this Directory

* [`producer_consumer.cpp`](./producer_consumer.cpp): Complete, deadlock-free bounded queue implementation with multiple producer and consumer threads.
