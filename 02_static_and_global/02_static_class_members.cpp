#include <iostream>
#include <string>
#include <memory>

class Player {
private:
 std::string name;

public:
 // Static Member Variable: Shared across all Player instances
 static int activePlayers;

 Player(std::string playerName) : name{playerName} {
 activePlayers++;
 std::cout << "[+] Player '" << name << "' joined. Active: " << activePlayers << "\n";
 }

 ~Player() {
 activePlayers--;
 std::cout << "[-] Player '" << name << "' left. Active: " << activePlayers << "\n";
 }

 // Static Member Function: Belongs to Player class, has no 'this' pointer
 static void displayServerStats() {
 std::cout << ">>> SERVER STATS: Total connected players = " << activePlayers << "\n";
 // name = "Admin"; // COMPILE ERROR: Cannot access non-static member 'name' without an instance!
 }
};

// Static class members must be defined outside the class:
int Player::activePlayers = 0;

int main() {
  // 1. Calling static function WITHOUT creating any Player object:
  Player::displayServerStats();

  // 2. Stack Allocation (Automatic storage - Recommended in modern C++):
  // Automatically destroyed when going out of scope; no manual delete needed.
  std::cout << "\n--- 1. Stack Allocation ---\n";
  Player p1("Alice");
  Player::displayServerStats();

  // 3. Raw Pointer on Heap (Manual memory management with new / delete):
  // Must manually call delete, otherwise memory leaks occur.
  std::cout << "\n--- 2. Heap Allocation (Raw Pointer with new) ---\n";
  Player* p2 = new Player("Bob");
  Player::displayServerStats();
  delete p2; // manual cleanup
  Player::displayServerStats();

  // 4. Smart Pointers (Modern C++ Heap Allocation):
  // std::unique_ptr: Exclusive ownership, frees memory automatically when out of scope.
  std::cout << "\n--- 3. Smart Pointer (std::unique_ptr) ---\n";
  {
    std::unique_ptr<Player> p3 = std::make_unique<Player>("Charlie");
    Player::displayServerStats();
  } // p3 automatically destroyed here!
  Player::displayServerStats();

  // std::shared_ptr: Shared ownership with reference counting, frees when ref count drops to 0.
  std::cout << "\n--- 4. Smart Pointer (std::shared_ptr) ---\n";
  {
    std::shared_ptr<Player> p4 = std::make_shared<Player>("Diana");
    {
      std::shared_ptr<Player> p4_copy = p4; // Ref count = 2
      std::cout << "p4 use_count: " << p4.use_count() << "\n";
    } // p4_copy destroyed, Ref count = 1
    std::cout << "p4 use_count: " << p4.use_count() << "\n";
  } // p4 destroyed, Ref count = 0 -> Player "Diana" deleted!
  Player::displayServerStats();

  // 5. Block Scope Demo (Stack):
  std::cout << "\n--- 5. Block Scope (Stack) ---\n";
  {
    Player temp("Guest_123");
    Player::displayServerStats();
  } // temp destroyed here

  Player::displayServerStats();

  std::cout << "\n--- Exiting main (p1 will be destroyed) ---\n";
  return 0;
}
