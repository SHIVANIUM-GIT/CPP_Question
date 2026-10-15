#include <iostream>
#include <mutex>

std::mutex testMutex;

// 1. A Custom RAII Class managing a native resource
class FileHandleRAII {
private:
 std::string filename;
public:
 FileHandleRAII(std::string name) : filename{name} {
 std::cout << "[RAII] File '" << filename << "' opened successfully.\n";
 }

 ~FileHandleRAII() {
 std::cout << "[RAII] File '" << filename << "' automatically closed in destructor!\n";
 }
};

void demoWithoutRAII(bool errorOccurred) {
 std::cout << "\n--- Function Without RAII ---\n";
 testMutex.lock(); // Manual lock
 std::cout << "Mutex locked manually.\n";

 if (errorOccurred) {
 std::cout << " Early error exit without unlocking!\n";
 // testMutex.unlock() is NEVER reached! The mutex remains permanently locked!
 testMutex.unlock(); // Unlocked here only to prevent hanging the rest of the demo
 return;
 }
 testMutex.unlock();
}

void demoWithRAII(bool errorOccurred) {
 std::cout << "\n--- Function WITH RAII ---\n";
 // std::lock_guard is an RAII class that locks in constructor and unlocks in destructor
 std::lock_guard<std::mutex> lock(testMutex);
 std::cout << "Mutex locked via std::lock_guard.\n";

 FileHandleRAII file("database.log");

 if (errorOccurred) {
 std::cout << " Early error exit encountered!\n";
 return; // Both file and mutex are safely destroyed and freed automatically!
 }
}

int main() {
 demoWithoutRAII(false);
 demoWithRAII(true); // Exits early on error, but RAII cleans up everything!

 std::cout << "\nProgram finished safely.\n";
 return 0;
}
