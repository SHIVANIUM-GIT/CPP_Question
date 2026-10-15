#include <iostream>
#include <string>

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

 // 2. Creating Player objects:
 Player* p1 = new Player("Alice");
 Player* p2 = new Player("Bob");

 Player::displayServerStats();

 {
 Player temp("Guest_123");
 Player::displayServerStats();
 } // temp goes out of scope here and is destroyed

 Player::displayServerStats();

 delete p1;
 delete p2;

 Player::displayServerStats();

 return 0;
}
