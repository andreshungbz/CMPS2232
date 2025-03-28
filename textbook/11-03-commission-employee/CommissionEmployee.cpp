//
// Created by andreshung on 1/24/25.
//

#include "CommissionEmployee.h"

#include <iomanip>
#include <stdexcept>
#include <sstream>

CommissionEmployee::CommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, double sales, double rate) {
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
}

void CommissionEmployee::setFirstName(const std::string& first) {
    firstName = first;
}

std::string CommissionEmployee::getFirstName() const {
    return firstName;
}

void CommissionEmployee::setLastName(const std::string& last) {
    lastName = last;
}

std::string CommissionEmployee::getLastName() const {
    return lastName;
}

void CommissionEmployee::setSocialSecurityNumber(const std::string& ssn) {
    socialSecurityNumber = ssn;
}

std::string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

void CommissionEmployee::setGrossSales(double sales) {
    if (sales < 0.0) {
        throw std::invalid_argument("Gross sales must be >= 0.0");
    }

    grossSales = sales;
}

double CommissionEmployee::getGrossSales() const {
    return grossSales;
}

void CommissionEmployee::setCommissionRate(double rate) {
    if (rate <= 0.0 || rate >= 1.0) {
        throw std::invalid_argument("Commission rate must be > 0.0 and < 1.0");
    }

    commissionRate = rate;
}

double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

double CommissionEmployee::earnings() const {
    return commissionRate * grossSales;
}

std::string CommissionEmployee::toString() const {
    std::ostringstream output;
    output << std::fixed << std::setprecision(2);
    output << "commission employee: " << firstName << " " << lastName
        << "\nsocial security number: " << socialSecurityNumber
        << "\ngross sales: " << grossSales
        << "\ncommission rate: " << commissionRate;

    return output.str();
}
