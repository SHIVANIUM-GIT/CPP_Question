#include <iostream>

class BaseWithoutVirtual {
public:
    BaseWithoutVirtual() { std::cout << "BaseWithoutVirtual constructed\n"; }
    ~BaseWithoutVirtual() { std::cout << "BaseWithoutVirtual destroyed\n"; } // ❌ NOT virtual!
};

class DerivedWithoutVirtual : public BaseWithoutVirtual {
    int* data;
public:
    DerivedWithoutVirtual() : data{new int[100]} { 
        std::cout << "DerivedWithoutVirtual allocated 100 ints\n"; 
    }
    ~DerivedWithoutVirtual() {
        delete[] data;
        std::cout << "DerivedWithoutVirtual freed 100 ints\n";
    }
};

class BaseWithVirtual {
public:
    BaseWithVirtual() { std::cout << "BaseWithVirtual constructed\n"; }
    virtual ~BaseWithVirtual() { std::cout << "BaseWithVirtual destroyed\n"; } // ✅ VIRTUAL!
};

class DerivedWithVirtual : public BaseWithVirtual {
    int* data;
public:
    DerivedWithVirtual() : data{new int[100]} { 
        std::cout << "DerivedWithVirtual allocated 100 ints\n"; 
    }
    ~DerivedWithVirtual() override {
        delete[] data;
        std::cout << "DerivedWithVirtual freed 100 ints\n";
    }
};

int main() {
    std::cout << "=== Test 1: Deleting without virtual destructor ===\n";
    BaseWithoutVirtual* p1 = new DerivedWithoutVirtual();
    delete p1; // Notice Derived destructor is SKIPPED (Memory leak!)

    std::cout << "\n=== Test 2: Deleting WITH virtual destructor ===\n";
    BaseWithVirtual* p2 = new DerivedWithVirtual();
    delete p2; // Derived destructor runs FIRST, then Base destructor!

    return 0;
}
