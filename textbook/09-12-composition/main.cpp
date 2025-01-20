#include <iostream>

#include "Date.h"
#include "Employee.h"

int main() {
    Date birth{7, 24, 1949};
    Date hire{3, 12, 1988};
    Employee manager{"Bob", "Blue", birth, hire};

    std::cout << "\n" << manager.toString() << std::endl;

    return 0;
}