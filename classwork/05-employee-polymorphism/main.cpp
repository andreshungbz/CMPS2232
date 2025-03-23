#include "Employee.h"
#include "Manager.h"
#include "Intern.h"
#include "Contractor.h"

#include <iostream>
#include <vector>

int main() {
    auto* manager = new Manager{1, "John Doe", 10000, "Accounting"};
    auto* intern = new Intern{2, "George Philip", 5000, manager};
    auto* contractor = new Contractor{3, "Saul Goodman", 50000, 24};

    std::vector<Employee*> employees{manager, intern, contractor};

    for (const Employee* e : employees) {
        e->print();
        std::cout << '\n';
    }

    for (Employee* e : employees) {
        delete e;
    }

    return 0;
}
