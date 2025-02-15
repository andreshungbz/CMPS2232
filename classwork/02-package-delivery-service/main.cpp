#include <iomanip>
#include <iostream>
#include <vector>

#include "TwoDayPackage.h"
#include "OvernightPackage.h"

void displayPackages(const std::vector<Package*>& packages);

int main() {
    std::vector<Package*> packages;
    packages.push_back(new TwoDayPackage{30.0, 15.0, "John", "12893", "Jane", "68954", 2.0});
    packages.push_back(new OvernightPackage{100.0, 25.0, "Greg", "68665", "Sally", "99954", 5.0});
    packages.push_back(new Package{14.0, 5.0, "Traves", "55435", "Paul", "58666"});

    std::cout << std::fixed << std::setprecision(2);
    displayPackages(packages);

    return 0;
}

void displayPackages(const std::vector<Package*>& packages) {
    std::cout << "Display All Packages\n\n";

    for (const Package* const p : packages) {
        p->print();
        std::cout << '\n';
    }
}