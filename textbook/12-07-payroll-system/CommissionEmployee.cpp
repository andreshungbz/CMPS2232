#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "CommissionEmployee.h"

CommissionEmployee::CommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, double sales, double rate)
    : Employee(first, last, ssn) {
    setGrossSales(sales);
    setCommissionRate(rate);
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
    return getCommissionRate() * getGrossSales();
}

std::string CommissionEmployee::toString() const {
    std::ostringstream output;
    output << std::fixed << std::setprecision(2);
    output << "commission employee: " << Employee::toString()
        << "\ngross sales: " << getGrossSales()
        << "; commission rate: " << getCommissionRate();

    return output.str();
}
