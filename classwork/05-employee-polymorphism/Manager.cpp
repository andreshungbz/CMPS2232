#include "Manager.h"
#include <iostream>

Manager::Manager(int id, const std::string& name, int salary, const std::string& department)
    : Employee{id, name, salary}, m_department{department} {}

std::string Manager::getDepartment() const {
    return m_department;
}

void Manager::setDepartment(const std::string& department) {
    m_department = department;
}

void Manager::print() const {
    std::cout << "Manager ";
    Employee::print();
    std::cout << "Department: " << getDepartment() << '\n';
}
