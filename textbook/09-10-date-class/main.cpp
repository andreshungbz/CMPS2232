#include <iostream>

#include "Date.h"

int main() {
    Date date1{7, 4, 2004};
    Date date2;

    std::cout << "date1 = " << date1.toString()
        << "\ndate2 = " << date2.toString() << "\n\n";

    date2 = date1;

    std::cout << "After default memberwise assignment, date2 = "
        << date2.toString() << std::endl;

    return 0;
}