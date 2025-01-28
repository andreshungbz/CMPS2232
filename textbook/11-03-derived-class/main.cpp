#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h"

int main() {
    BasePlusCommissionEmployee employee{"Bob", "Lewis", "333-33-3333", 5000, 0.04, 300};

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Employee information obtained by get functions: \n"
        << "\nFirst name is " << employee.getFirstName()
        << "\nLast name is " << employee.getLastName()
        << "\nSocial security number is " << employee.getSocialSecurityNumber()
        << "\nGross sales is " << employee.getGrossSales()
        << "\nCommission rate is " << employee.getCommissionRate()
        << "\nBase salary is " << employee.getBaseSalary() << std::endl;

    employee.setBaseSalary(1000);

    std::cout << "\nUpdated employee information from function toString: \n\n" << employee.toString();

    std::cout << "\n\nEmployee's earnings: $" << employee.earnings() << std::endl;

    return 0;
}