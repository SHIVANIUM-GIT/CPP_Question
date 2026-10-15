#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

void printVector(const std::vector<int>& v, const std::string& label) {
    std::cout << label << ": [ ";
    for (int x : v) std::cout << x << " ";
    std::cout << "]\n";
}

void printList(const std::list<int>& l, const std::string& label) {
    std::cout << label << ": [ ";
    for (int x : l) std::cout << x << " ";
    std::cout << "]\n";
}

int main() {
    std::cout << "=== 1. std::vector Operations ===\n";
    std::vector<int> vec = {10, 20, 30, 40, 50, 30};
    printVector(vec, "Initial vector");

    // UPDATE: O(1) random access
    vec[1] = 99; // Change 20 to 99
    printVector(vec, "After vec[1] = 99");

    // DELETE by position: O(N) due to shifting
    vec.erase(vec.begin()); // Erases first element (10)
    printVector(vec, "After erase index 0");

    // DELETE by value (Classic Erase-Remove Idiom for pre-C++20):
    // Removes all occurrences of 30:
    vec.erase(std::remove(vec.begin(), vec.end(), 30), vec.end());
    printVector(vec, "After Erase-Remove 30");

    std::cout << "\n=== 2. std::list Operations ===\n";
    std::list<int> lst = {10, 20, 30, 40, 50, 30};
    printList(lst, "Initial list");

    // UPDATE: No index access (lst[1] is invalid). Must advance iterator:
    auto it = lst.begin();
    std::advance(it, 1); // Move to 2nd element
    *it = 99;
    printList(lst, "After iterator update (*it = 99)");

    // DELETE by iterator position: O(1) node unlinking
    lst.erase(lst.begin()); // Erases 10
    printList(lst, "After erase head");

    // DELETE by value: std::list has a dedicated member function remove()!
    lst.remove(30); // Instantly finds and removes all 30s
    printList(lst, "After lst.remove(30)");

    return 0;
}
