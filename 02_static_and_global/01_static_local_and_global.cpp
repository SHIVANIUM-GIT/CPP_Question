#include <iostream>

// 1. Global Variable: Visible anywhere in this file (and across other files with 'extern')
int globalCounter = 0;

void normalFunction() {
    int normalLocal = 0; // Destroyed on function return, re-initialized to 0 on next call
    static int staticLocal = 0; // Initialized ONCE. Lives in Data Segment for the entire program!

    normalLocal++;
    staticLocal++;
    globalCounter++;

    std::cout << "normalLocal: " << normalLocal 
              << " | staticLocal: " << staticLocal 
              << " | globalCounter: " << globalCounter << "\n";
}

int main() {
    std::cout << "Calling normalFunction() 3 times:\n";
    normalFunction();
    normalFunction();
    normalFunction();

    // staticLocal is NOT accessible here (scoped strictly to normalFunction)
    // globalCounter IS accessible here:
    std::cout << "Direct access to globalCounter in main(): " << globalCounter << "\n";

    return 0;
}
