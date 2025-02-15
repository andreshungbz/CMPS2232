#include "Package.h"

#include <iostream>

Package::Package()
    : weightInOunce{}, costPerOunce{}, senderName{}, senderZip{}, recipientName{}, recipientZip{} {}

Package::Package(double weight, double cost, const std::string& sName, const std::string& sZip, const std::string& rName, const std::string& rZip)
    : weightInOunce{weight}, costPerOunce{cost}, senderName{sName}, senderZip{sZip}, recipientName{rName}, recipientZip{rZip} {}

// getters

double Package::getWeigthInOunce() const {
    return weightInOunce;
}

double Package::getCostPerOunce() const {
    return costPerOunce;
}

std::string Package::getSenderName() const {
    return senderName;
}

std::string Package::getSenderZip() const {
    return senderZip;
}

std::string Package::getRecipientName() const {
    return recipientName;
}

std::string Package::getRecipientZip() const {
    return recipientZip;
}

// setters

void Package::setWeightInOunce(double weight) {
    weightInOunce = weight > 0.0 ? weight : 0.0;
}

void Package::setCostPerOunce(double cost) {
    costPerOunce = cost > 0.0 ? cost : 0.0;
}

void Package::setSenderName(const std::string& sName) {
    senderName = sName;
}

void Package::setSenderZip(const std::string& sZip) {
    senderZip = sZip;
}

void Package::setRecipientName(const std::string& rName) {
    recipientName = rName;
}

void Package::setRecipientZip(const std::string& rZip) {
    recipientZip = rZip;
}

double Package::calcCost() const {
    return getWeigthInOunce() * getCostPerOunce();
}

void Package::print() const {
    std::cout << "Package Details\n";
    printDetails();
    std::cout << "Calculated Cost $" << calcCost() << '\n';
}

void Package::printDetails() const {
    std::cout
        << "Weight in Ounce: " << getWeigthInOunce() << '\n'
        << "Cost per Ounce: $" << getCostPerOunce() << '\n'
        << "Sender Name: " << getSenderName() << '\n'
        << "Sender ZIP: " << getSenderZip() << '\n'
        << "Recipient Name: " << getRecipientName() << '\n'
        << "Recipient Zip: " << getRecipientZip() << '\n';
}
