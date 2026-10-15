#include <iostream>
#include <string_view>
#include <unistd.h>

// 1. Simulating how std::cout works with custom chaining
class MiniCout {
public:
    // Returns MiniCout& (*this) to enable chaining!
    MiniCout& operator<<(std::string_view text) {
        write(STDOUT_FILENO, text.data(), text.size());
        return *this; // Return reference to self
    }

    MiniCout& operator<<(int number) {
        std::string s = std::to_string(number);
        write(STDOUT_FILENO, s.data(), s.size());
        return *this;
    }
};

MiniCout mini_cout;

// 2. Custom Point class demonstrating non-member operator<<
class Point {
public:
    int x, y;
    Point(int xVal, int yVal) : x{xVal}, y{yVal} {}

    // Overloaded as non-member friend function:
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os; // Return stream by reference for further chaining!
    }
};

int main() {
    std::cout << "--- 1. Testing MiniCout Chaining ---\n";
    // Works because operator<< returns MiniCout& (*this):
    mini_cout << "Hello " << "World! " << 42 << "\n";

    std::cout << "\n--- 2. Custom Class Stream Output ---\n";
    Point pt(10, 25);
    // Left-hand operand is std::cout, right-hand is pt:
    std::cout << "Coordinate point: " << pt << " logged successfully!\n";

    return 0;
}
