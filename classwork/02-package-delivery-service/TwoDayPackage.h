#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage: public Package {
public:
    // constructors
    TwoDayPackage();
    TwoDayPackage(double weight, double cost, const std::string& sName, const std::string& sZip,
        const std::string& rName, const std::string& rZip, double fee);

    // destructor
    virtual ~TwoDayPackage() = default;

    // getters
    double getFlatFee() const;

    // setters
    void setFlatFee(double fee);

    double calcCost() const override;
    void print() const override;
private:
    double flatFee;
};



#endif // TWODAYPACKAGE_H
