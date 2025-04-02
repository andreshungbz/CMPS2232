#include "Employee.h"
#include <iostream>

Employee::Employee(int id, const std::string& name, int salary)
    : m_id{id}, m_name{name}, m_salary{salary > 0 ? salary : 0} {}

int Employee::getID() const {
    return m_id;
}

std::string Employee::getName() const {
    return m_name;
}

int Employee::getSalary() const {
    return m_salary;
}

void Employee::setID(int id) {
    m_id = id;
}

void Employee::setName(const std::string& name) {
    m_name = name;
}

void Employee::setSalary(int salary) {
    m_salary = salary > 0 ? salary : 0;
}

void Employee::print() const {
    std::cout << "Employee Details\n"
        << "ID: " << getID() << '\n'
        << "Name: " << getName() << '\n'
        << "Salary: $" << getSalary() << '\n';
}
