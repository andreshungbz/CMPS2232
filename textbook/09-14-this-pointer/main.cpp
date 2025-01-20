#include <iostream>

class Test {
public:
    explicit Test(int);
    void print() const;
private:
    int x{0};
};

Test::Test(int value) : x{value} {}

void Test::print() const {
    std::cout << "        x = " << x;
    std::cout << "\n  this->x = " << this->x;
    std::cout << "\n(*this).x = " << (*this).x << std::endl;
}

int main() {
    Test testObject{12};
    testObject.print();

    return 0;
}