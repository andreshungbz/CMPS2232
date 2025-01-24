#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h"

int main() {
    CommissionEmployee employee{"Sue", "Jones", "222-22-2222", 10000, 0.06};

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Employee information obtained by get functions: \n"
        << "\nFirst name is " << employee.getFirstName()
        << "\nLast name is " << employee.getLastName()
        << "\nSocial security number is " << employee.getSocialSecurityNumber()
        << "\nGross sales is " << employee.getGrossSales()
        << "\nCommission rate is " << employee.getCommissionRate() << std::endl;

    employee.setGrossSales(8000);
    employee.setCommissionRate(0.1);

    std::cout << "\nUpdated employee information from function toString: \n\n" << employee.toString();

    std::cout << "\n\nEmployee's earnings: $" << employee.earnings() << std::endl;

    return 0;
}