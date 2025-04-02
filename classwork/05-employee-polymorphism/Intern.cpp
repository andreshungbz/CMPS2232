#include "Intern.h"
#include <iostream>

Intern::Intern(int id, const std::string& name, int salary, Employee* mentor)
    : Employee{id, name, salary}, m_mentor{mentor} {}

Employee* Intern::getMentor() const {
    return m_mentor;
}

void Intern::setMentor(Employee* mentor) {
    m_mentor = mentor;
}

void Intern::print() const {
    std::cout << "Intern ";
    Employee::print();
    std::cout << '[' << getName() << "'s Mentor] ";
    m_mentor->print();
}
