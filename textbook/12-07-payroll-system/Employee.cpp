#include <sstream>
#include "Employee.h"

Employee::Employee(const std::string& first, const std::string& last, const std::string& ssn)
    : firstName{first}, lastName{last}, socialSecurityNumber{ssn} {}

void Employee::setFirstName(const std::string& first) {
    firstName = first;
}

std::string Employee::getFirstName() const {
    return firstName;
}

void Employee::setLastName(const std::string& last) {
    lastName = last;
}

std::string Employee::getLastName() const {
    return lastName;
}

void Employee::setSocialSecurityNumber(const std::string& ssn) {
    socialSecurityNumber = ssn;
}

std::string Employee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

std::string Employee::toString() const {
    return getFirstName() + " " + getLastName() + "\nsocial security number: " + getSocialSecurityNumber();
}
