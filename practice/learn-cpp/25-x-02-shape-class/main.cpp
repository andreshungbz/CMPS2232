#include <iostream>
#include <vector>

class Shape {
public:
    friend std::ostream& operator<<(std::ostream& out, const Shape& s) {
        return s.print(out);
    }

    virtual ~Shape() = default;
    virtual std::ostream& print(std::ostream& out) const = 0;
};

class Point {
public:
    Point(int x, int y)
        : m_x{ x }, m_y{ y } {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        return out << "Point(" << p.m_x << ", " << p.m_y << ')';
    }
private:
    int m_x{};
    int m_y{};
};

class Triangle: public Shape {
public:
    ~Triangle() override = default;

    Triangle(const Point& x, const Point& y, const Point& z)
        : m_point_x{x}, m_point_y{y}, m_point_z{z} {}

    std::ostream& print(std::ostream& out) const override {
        out << "Triangle(" << m_point_x << ", " << m_point_y << ", " << m_point_z << ')';
        return out;
    }
private:
    Point m_point_x;
    Point m_point_y;
    Point m_point_z;
};

class Circle: public Shape {
public:
    ~Circle() override = default;

    Circle(const Point& c, int radius)
        : m_point_center{c}, m_radius{radius} {}

    std::ostream& print(std::ostream& out) const override {
        out << "Circle(" << m_point_center << ", radius " << m_radius << ')';
        return out;
    }

    [[nodiscard]] int getRadius() const { return m_radius; }
private:
    Point m_point_center;
    int m_radius;
};

int getLargestRadius(const std::vector<Shape*>& v) {
    int largest = -1;
    for (Shape* s : v) {
        Circle* c{dynamic_cast<Circle*>(s)};
        if (c) {
            if (c->getRadius() > largest) {
                largest = c->getRadius();
            }
        }
    }

    return largest;
}

int main() {
    Circle c{ Point{ 1, 2 }, 7 };
    std::cout << c << '\n';

    Triangle t{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }};
    std::cout << t << '\n';

    std::cout << '\n';

    std::vector<Shape*> v{
        new Circle{Point{ 1, 2 }, 7},
        new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
        new Circle{Point{ 7, 8 }, 3}
    };

    // print each shape in vector v on its own line here
    for (const Shape* s : v) {
        std::cout << *s << '\n';
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

    // delete each element in the vector here
    for (auto& s : v) {
        delete s;
    }

    return 0;
}