#include <iostream>
#include <string>
#include <string_view>
#include <tuple>
#include <vector>
#include <algorithm>

// --- C++20 Concept Demonstration ---
#if __cplusplus >= 202002L
#include <concepts>
template <std::integral T>
T addIntegersOnly(T a, T b) {
    return a + b;
}
#endif

// --- C++17 string_view (Zero-copy string parameter) ---
void printSubstring(std::string_view sv) {
    std::cout << "[C++17 string_view] Content: " << sv << " (Length: " << sv.length() << ")\n";
}

int main() {
    std::cout << "=== 1. C++11 Highlights ===\n";
    // Auto type deduction & Lambdas:
    std::vector<int> nums = {5, 2, 8, 1, 9};
    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
    std::cout << "Sorted with C++11 lambda: ";
    for (auto n : nums) std::cout << n << " ";
    std::cout << "\n";

    std::cout << "\n=== 2. C++17 Highlights ===\n";
    // Structured Binding (unpacking a tuple/pair/struct):
    std::tuple<std::string, int, double> userRecord = {"Alice", 28, 95.5};
    auto [name, age, score] = userRecord; // Unpacks into 3 variables!
    std::cout << "User: " << name << ", Age: " << age << ", Score: " << score << "\n";

    // string_view: Takes string without allocating heap memory:
    std::string fullGreeting = "Hello, C++ World!";
    printSubstring(fullGreeting);

    std::cout << "\n=== 3. C++20 Highlights ===\n";
#if __cplusplus >= 202002L
    int sum = addIntegersOnly(10, 20); // ✅ Works for integral types
    std::cout << "[C++20 Concept] addIntegersOnly(10, 20) = " << sum << "\n";
    // addIntegersOnly(3.14, 2.71); // ❌ COMPILE ERROR: Constraints not satisfied!
#else
    std::cout << "Compile with -std=c++20 to test C++20 Concepts!\n";
#endif

    return 0;
}
