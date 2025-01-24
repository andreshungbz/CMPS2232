//
// Created by andreshung on 1/24/25.
//

#include "BasePlusCommissionEmployee.h"

#include <iomanip>
#include <stdexcept>
#include <sstream>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, double sales, double rate, double salary) {
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
    setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setFirstName(const std::string& first) {
    firstName = first;
}

std::string BasePlusCommissionEmployee::getFirstName() const {
    return firstName;
}

void BasePlusCommissionEmployee::setLastName(const std::string& last) {
    lastName = last;
}

std::string BasePlusCommissionEmployee::getLastName() const {
    return lastName;
}

void BasePlusCommissionEmployee::setSocialSecurityNumber(const std::string& ssn) {
    socialSecurityNumber = ssn;
}

std::string BasePlusCommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

void BasePlusCommissionEmployee::setGrossSales(double sales) {
    if (sales < 0.0) {
        throw std::invalid_argument("Gross sales must be >= 0.0");
    }

    grossSales = sales;
}

double BasePlusCommissionEmployee::getGrossSales() const {
    return grossSales;
}

void BasePlusCommissionEmployee::setCommissionRate(double rate) {
    if (rate <= 0.0 || rate >= 1.0) {
        throw std::invalid_argument("Commission rate must be > 0.0 and < 1.0");
    }

    commissionRate = rate;
}

double BasePlusCommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    if (salary < 0.0) {
        throw std::invalid_argument("Salary must be >= 0.0");
    }

    baseSalary = salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}


double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + (commissionRate * grossSales);
}

std::string BasePlusCommissionEmployee::toString() const {
    std::ostringstream output;
    output << std::fixed << std::setprecision(2);
    output << "commission employee: " << firstName << " " << lastName
        << "\nsocial security number: " << socialSecurityNumber
        << "\ngross sales: " << grossSales
        << "\ncommission rate: " << commissionRate
        << "\nbase salary: " << baseSalary;

    return output.str();
}
