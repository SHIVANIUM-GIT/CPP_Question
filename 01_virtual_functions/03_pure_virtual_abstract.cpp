#include <iostream>
#include <vector>
#include <memory>

// Abstract Base Class: Cannot be instantiated directly
class Shape {
public:
    // Pure virtual functions: Must be implemented by concrete derived classes
    virtual double area() const = 0;
    virtual void draw() const = 0;

    // Base classes with virtual methods should always have a virtual destructor
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius{r} {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void draw() const override {
        std::cout << "Drawing Circle with area: " << area() << "\n";
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width{w}, height{h} {}

    double area() const override {
        return width * height;
    }

    void draw() const override {
        std::cout << "Drawing Rectangle with area: " << area() << "\n";
    }
};

int main() {
    // Shape s; // ❌ COMPILE ERROR: Cannot declare variable of abstract type 'Shape'

    // We can hold pointers to Shape:
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));

    // Dynamic dispatch on pure virtual interface:
    for (const auto& shape : shapes) {
        shape->draw();
    }

    return 0;
}
