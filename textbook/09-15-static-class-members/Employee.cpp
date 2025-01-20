#include <iostream>

#include "Employee.h"

unsigned int Employee::count{0};
unsigned int Employee::getCount() {
    return count;
}

Employee::Employee(const std::string& first, const std::string& last)
    : firstName{first}, lastName{last} {
    ++count;
    std::cout << "Employee constructor for " << firstName
        << ' ' << lastName << " called." << std::endl;
}

Employee::~Employee() {
    std::cout << "~Employee() called for " << firstName
        << ' ' << lastName << std::endl;
    --count;
}

std::string Employee::getFirstName() const {
    return firstName;
}

std::string Employee::getLastName() const {
    return lastName;
}
