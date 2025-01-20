#include <iostream>
#include <sstream>

#include "Employee.h"
#include "Date.h"

Employee::Employee(const std::string& first, const std::string& last, const Date& dateOfBirth, const Date& dateOfHire)
    : firstName{first}
    , lastName{last}
    , birthDate{dateOfBirth}
    , hireDate{dateOfHire} {
    std::cout << "Employee object constructor: "
        << firstName << ' ' << lastName << std::endl;
}
std::string Employee::toString() const {
    std::ostringstream output;
    output << lastName << ", " << firstName << " Hired: "
        << hireDate.toString() << " Birthday: " << birthDate.toString();
    return output.str();
}

Employee::~Employee() {
    std::cout << "Employee object destructor: "
        << lastName << ", " << firstName << std::endl;
}
