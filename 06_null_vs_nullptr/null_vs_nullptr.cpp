#include <iostream>
#include <cstddef>

void testOverload(int x) {
 std::cout << "[Called] testOverload(int): x = " << x << "\n";
}

void testOverload(char* ptr) {
 std::cout << "[Called] testOverload(char*): ptr = " << (void*)ptr << "\n";
}

void testOverload(std::nullptr_t) {
 std::cout << "[Called] testOverload(std::nullptr_t): specialized null handler!\n";
}

int main() {
 std::cout << "--- 1. Passing integer 0 ---\n";
 testOverload(0); // Calls testOverload(int)

 std::cout << "\n--- 2. Passing NULL (Ambiguous in C++!) ---\n";
 // THE FAMOUS BUG: The line below causes a COMPILE ERROR:
 // "error: call of overloaded 'testOverload(NULL)' is ambiguous"
 // Because NULL can match 'int' (0) OR 'char*' (0 as null pointer)!
 // testOverload(NULL); // UNCOMMENT TO SEE COMPILER AMBIGUITY ERROR!
 std::cout << "testOverload(NULL) is ambiguous and fails to compile!\n";

 std::cout << "\n--- 3. Passing nullptr (C++11 type-safe) ---\n";
 // nullptr will NEVER match an integer. It matches std::nullptr_t or pointer types:
 testOverload(nullptr); // Calls testOverload(std::nullptr_t)

 char* myPtr = nullptr;
 testOverload(myPtr); // Calls testOverload(char*)

 return 0;
}
