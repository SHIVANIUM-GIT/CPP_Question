#include <iostream>

class Animal {
public:
 // Without virtual: compiler binds to Animal::sound() at compile time
 void soundNonVirtual() { 
 std::cout << "[Non-Virtual] Animal makes a sound\n"; 
 }

 // With virtual: compiler resolves call dynamically at runtime via vtable
 virtual void soundVirtual() { 
 std::cout << "[Virtual] Animal makes a sound\n"; 
 }

 virtual ~Animal() = default;
};

class Dog : public Animal {
public:
 void soundNonVirtual() { 
 std::cout << "[Non-Virtual] Dog barks: Woof!\n"; 
 }

 void soundVirtual() override { 
 std::cout << "[Virtual] Dog barks: Woof!\n"; 
 }
};

int main() {
 std::cout << "--- 1. Direct Object Call ---\n";
 Dog myDog;
 myDog.soundNonVirtual(); // Calls Dog::soundNonVirtual
 myDog.soundVirtual(); // Calls Dog::soundVirtual

 std::cout << "\n--- 2. Call via Base Class Pointer (Animal*) ---\n";
 Animal* polyPtr = &myDog;

 // Static Binding (Binds based on pointer type: Animal)
 polyPtr->soundNonVirtual(); // Prints Animal's sound! 

 // Dynamic Binding (Binds based on actual object: Dog via vtable)
 polyPtr->soundVirtual(); // Prints Dog's sound! 

 return 0;
}
