#include <iostream>

#include "Employee.h"

int main() {
    std::cout << "Number of employees before instantiation of any objects is "
        << Employee::getCount() << std::endl;

    {
        Employee e1{"Susan", "Baker"};
        Employee e2{"Robert", "Jones"};

        std::cout << "Number of employees after objects are instantiated is "
            << Employee::getCount();

        std::cout << "\n\nEmployee 1: "
            << e1.getFirstName() << " " << e1.getLastName()
            << "\nEmployee 2: "
            << e2.getFirstName() << " " << e2.getLastName() << "\n\n";
    }

    std::cout << "\nNumber of employees after objects are deleted is "
        << Employee::getCount() << std::endl;

    return 0;
}