#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage: public Package {
public:
    // constructor
    OvernightPackage();
    OvernightPackage(double weight, double cost, const std::string& sName, const std::string& sZip,
        const std::string& rName, const std::string& rZip, double extraFee);

    // destructor
    virtual ~OvernightPackage() = default;

    // getters
    double getExtraFeePerOunce() const;

    // setters
    void setExtraFeePerOunce(double extraFee);

    double calcCost() const override;
    void print() const override;
private:
    double extraFeePerOunce;
};



#endif // OVERNIGHTPACKAGE_H
