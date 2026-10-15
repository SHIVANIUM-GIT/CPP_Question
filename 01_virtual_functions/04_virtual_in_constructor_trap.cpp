#include <iostream>

class Base {
public:
    Base() {
        std::cout << "[Base Constructor] Calling virtual function setup()...\n";
        // ⚠️ TRAP: In C++, the Derived object does NOT exist yet!
        // Virtual dispatch is disabled; this executes Base::setup(), NOT Derived::setup()!
        setup();
    }

    virtual void setup() {
        std::cout << "  -> Base::setup() executed.\n";
    }

    virtual ~Base() = default;
};

class Derived : public Base {
    int secretCode;
public:
    Derived() : secretCode{42} {
        std::cout << "[Derived Constructor] Finished.\n";
    }

    void setup() override {
        // If this were called from Base constructor, secretCode would be garbage/uninitialized!
        std::cout << "  -> Derived::setup() executed with secretCode = " << secretCode << "\n";
    }
};

int main() {
    std::cout << "Instantiating Derived object:\n";
    Derived d;

    std::cout << "\nExplicit call after full construction:\n";
    d.setup(); // Now it calls Derived::setup() properly!

    return 0;
}
