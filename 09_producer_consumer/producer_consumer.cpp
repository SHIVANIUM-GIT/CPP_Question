#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

template <typename T>
class ThreadSafeQueue {
private:
 std::queue<T> queue;
 size_t capacity;
 std::mutex mtx;
 std::condition_variable not_full_cv; // Wakes up producers
 std::condition_variable not_empty_cv; // Wakes up consumers
 bool finished = false;

public:
 ThreadSafeQueue(size_t maxCapacity) : capacity{maxCapacity} {}

 // Producer calls push:
 void push(T value) {
 // std::unique_lock is an RAII lock required by condition_variable
 std::unique_lock<std::mutex> lock(mtx);

 // Wait while queue is full (handles spurious wakeups!):
 not_full_cv.wait(lock, [this]() { return queue.size() < capacity; });

 queue.push(value);
 std::cout << "[Producer] Pushed: " << value << " (Queue size: " << queue.size() << ")\n";

 // Notify one waiting consumer:
 not_empty_cv.notify_one();
 }

 // Consumer calls pop:
 bool pop(T& outValue) {
 std::unique_lock<std::mutex> lock(mtx);

 // Wait while queue is empty AND producers are still active:
 not_empty_cv.wait(lock, [this]() { return !queue.empty() || finished; });

 if (queue.empty() && finished) {
 return false; // Done processing
 }

 outValue = queue.front();
 queue.pop();
 std::cout << " [Consumer] Popped: " << outValue << " (Queue size: " << queue.size() << ")\n";

 // Notify one waiting producer:
 not_full_cv.notify_one();
 return true;
 }

 void shutdown() {
 std::unique_lock<std::mutex> lock(mtx);
 finished = true;
 not_empty_cv.notify_all(); // Wake up all waiting consumers to exit cleanly
 }
};

int main() {
 ThreadSafeQueue<int> boundedBuffer(3); // Max capacity of 3 items

 // Producer Thread
 std::thread producer([&]() {
 for (int i = 1; i <= 6; ++i) {
 boundedBuffer.push(i);
 std::this_thread::sleep_for(std::chrono::milliseconds(50));
 }
 boundedBuffer.shutdown();
 });

 // Consumer Thread
 std::thread consumer([&]() {
 int item;
 while (boundedBuffer.pop(item)) {
 std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
 }
 });

 producer.join();
 consumer.join();

 std::cout << "\nAll items produced and consumed successfully!\n";
 return 0;
}
