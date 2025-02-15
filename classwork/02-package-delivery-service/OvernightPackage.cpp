#include "OvernightPackage.h"

#include <iostream>

OvernightPackage::OvernightPackage()
    : Package{}, extraFeePerOunce{} {}

OvernightPackage::OvernightPackage(double weight, double cost, const std::string& sName, const std::string& sZip, const std::string& rName, const std::string& rZip, double extraFee)
    : Package{weight, cost, sName, sZip, rName, rZip}, extraFeePerOunce{extraFee} {}

double OvernightPackage::getExtraFeePerOunce() const {
    return extraFeePerOunce;
}

void OvernightPackage::setExtraFeePerOunce(double extraFee) {
    extraFeePerOunce = extraFee > 0.0 ? extraFee : 0.0;
}

double OvernightPackage::calcCost() const {
    return Package::calcCost() * getExtraFeePerOunce();
}

void OvernightPackage::print() const {
    std::cout << "Overnight Package Details";
    printDetails();
    std::cout << "Extra Fee per Ounce: " << getExtraFeePerOunce() << '\n';
    std::cout << "Calculated Cost: $" << calcCost() << '\n';
}
