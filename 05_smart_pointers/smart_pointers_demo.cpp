#include <iostream>
#include <memory>

class Resource {
public:
    std::string name;
    Resource(std::string n) : name{n} {
        std::cout << "[Resource] '" << name << "' acquired.\n";
    }
    ~Resource() {
        std::cout << "[Resource] '" << name << "' destroyed.\n";
    }
};

void demoUniquePtr() {
    std::cout << "\n--- 1. std::unique_ptr (Single Ownership) ---\n";
    std::unique_ptr<Resource> u1 = std::make_unique<Resource>("ConfigData");

    // std::unique_ptr<Resource> u2 = u1; // ❌ COMPILE ERROR: Cannot copy unique_ptr!
    
    // Transfer ownership using std::move:
    std::unique_ptr<Resource> u2 = std::move(u1);
    if (!u1) {
        std::cout << "u1 is now null after std::move!\n";
    }
    std::cout << "u2 now owns: " << u2->name << "\n";
} // u2 goes out of scope here -> ConfigData automatically destroyed!

void demoSharedAndWeakPtr() {
    std::cout << "\n--- 2. std::shared_ptr & std::weak_ptr ---\n";
    std::shared_ptr<Resource> s1 = std::make_shared<Resource>("SharedSession");
    std::cout << "Ref count of s1: " << s1.use_count() << "\n"; // 1

    std::weak_ptr<Resource> weakObserver = s1; // Does NOT increment ref count!
    std::cout << "Ref count after weak_ptr: " << s1.use_count() << "\n"; // Still 1

    {
        std::shared_ptr<Resource> s2 = s1; // Shared ownership!
        std::cout << "Inside block: Ref count is " << s1.use_count() << "\n"; // 2
    } // s2 destroyed here

    std::cout << "After block: Ref count is " << s1.use_count() << "\n"; // 1

    // Accessing through weak_ptr:
    if (auto locked = weakObserver.lock()) { // Safely promote to shared_ptr
        std::cout << "Observer confirmed resource is alive: " << locked->name << "\n";
    }
} // s1 goes out of scope -> SharedSession automatically destroyed!

int main() {
    demoUniquePtr();
    demoSharedAndWeakPtr();
    return 0;
}
