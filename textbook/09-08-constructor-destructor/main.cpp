#include <iostream>

#include "CreateAndDestroy.h"

void create();

CreateAndDestroy first{1, "(global before main)"};

int main() {
    std::cout << "\nMAIN FUNCTION: EXECUTION BEGINS" << std::endl;
    CreateAndDestroy second{2, "(local in main)"};
    static CreateAndDestroy third{3, "(local static in main)"};

    create();

    std::cout << "\nMAIN FUNCTION: EXECUTION RESUMES" << std::endl;
    CreateAndDestroy fourth{4, "(local in main)"};
    std::cout << "\nMAIN FUNCTION: EXECUTION ENDS" << std::endl;

    return 0;
}

void create() {
    std::cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << std::endl;
    CreateAndDestroy fifth{5, "(local in create)"};
    static CreateAndDestroy sixth{6, "(local static in create)"};
    CreateAndDestroy seventh{7, "(local in create)"};
    std::cout << "\nCREATE FUNCTION: EXECUTION ENDS" << std::endl;
}