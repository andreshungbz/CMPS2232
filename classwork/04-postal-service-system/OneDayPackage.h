#ifndef ONEDAYPACKAGE_H
#define ONEDAYPACKAGE_H

#include "Package.h"

class OneDayPackage: public Package {
public:
    // constructor
    OneDayPackage(int trackingNumber, const std::string& senderName, const std::string& senderAddress,
        const std::string& receiverName, const std::string& receiverAddress, double weight,
        double costPerUnitWeight, double flatFee);

    // destructor
    virtual ~OneDayPackage() = default;

    // member functions
    double calculateCost() const override;
    void printLabel() const override;
};

#endif // ONEDAYPACKAGE_H
