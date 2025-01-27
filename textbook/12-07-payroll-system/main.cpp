#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

void virtualViaPointer(const Employee* const);
void virtualViaReference(const Employee&);

int main() {
    std::cout << std::fixed << std::setprecision(2);

    SalariedEmployee salariedEmployee{"John", "Smith", "111-11-1111", 800};
    CommissionEmployee commissionEmployee{"Sue", "Jones", "333-33-3333", 10000, 0.06};
    BasePlusCommissionEmployee basePlusCommissionEmployee{"Bob", "Lewis", "444-44-4444", 5000, 0.04, 300};

    std::cout << "EMPLOYEES PROCESSED INDIVIDUALLY USING STATIC BINDING\n"
        << salariedEmployee.toString()
        << "\nearned $" << salariedEmployee.earnings() << "\n\n"
        << commissionEmployee.toString()
        << "\nearned $" << commissionEmployee.earnings() << "\n\n"
        << basePlusCommissionEmployee.toString()
        << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

    std::vector<Employee*> employees{&salariedEmployee, &commissionEmployee, &basePlusCommissionEmployee};

    std::cout << "EMPLOYEES PROCESSED POLYMORPHICALLY VIA DYNAMIC BINDING\n\n";

    std::cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS POINTERS\n";
    for (const Employee* employeePtr : employees) {
        virtualViaPointer(employeePtr);
    }

    std::cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS REFERENCES\n";
    for (const Employee* employeePtr : employees) {
        virtualViaReference(*employeePtr);
    }
}

void virtualViaPointer(const Employee* const baseClassPtr) {
    std::cout << baseClassPtr->toString()
        << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}

void virtualViaReference(const Employee& baseClassRef) {
    std::cout << baseClassRef.toString()
        << "\nearned $" << baseClassRef.earnings() << "\n\n";
}
