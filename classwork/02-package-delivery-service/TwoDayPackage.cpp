#include "TwoDayPackage.h"

#include <iostream>

TwoDayPackage::TwoDayPackage()
    : Package{}, flatFee{} {}

TwoDayPackage::TwoDayPackage(double weight, double cost, const std::string& sName, const std::string& sZip, const std::string& rName, const std::string& rZip, double fee)
    : Package{weight, cost, sName, sZip, rName, rZip}, flatFee{fee} {}

double TwoDayPackage::getFlatFee() const {
    return flatFee;
}

void TwoDayPackage::setFlatFee(double fee) {
    flatFee = fee > 0.0 ? fee : 0.0;
}

double TwoDayPackage::calcCost() const {
    return Package::calcCost() + getFlatFee();
}

void TwoDayPackage::print() const {
    std::cout << "Two Day Package Details\n";
    printDetails();
    std::cout << "Flat Fee: $" << getFlatFee() << '\n';
    std::cout << "Calculated Cost: $" << calcCost() << '\n';
}
