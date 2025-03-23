#include "Contractor.h"
#include <iostream>

Contractor::Contractor(int id, const std::string& name, int salary, int contractDuration)
    : Employee{id, name, salary}, m_contractDuration{contractDuration} {}

int Contractor::getContractDuration() const {
    return m_contractDuration;
}

void Contractor::setContractDuration(int contractDuration) {
    m_contractDuration = contractDuration;
}

void Contractor::print() const {
    std::cout << "Contractor ";
    Employee::print();
    std::cout << "Contract Duration: " << getContractDuration() << '\n';
}
