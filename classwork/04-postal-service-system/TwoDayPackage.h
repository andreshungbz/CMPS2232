#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage: public Package{
public:
    // constructor
    TwoDayPackage(int trackingNumber, const std::string& senderName, const std::string& senderAddress,
        const std::string& receiverName, const std::string& receiverAddress, double weight,
        double costPerUnitWeight, double flatFee);

    // destructor
    virtual ~TwoDayPackage()() = default;

    // member functions
    double calculateCost() const override;
    void printLabel() const override;
};

#endif // TWODAYPACKAGE_H
