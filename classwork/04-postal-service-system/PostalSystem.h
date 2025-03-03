#ifndef POSTALSYSTEM_H
#define POSTALSYSTEM_H

#include "Package.h"
#include "OneDayPackage.h"
#include "TwoDayPackage.h"
#include "Employee.h"

#include <string>
#include <vector>

class PostalSystem {
public:
    // system functions
    Employee* login(int employeeID, const std::string& password);
    bool addPackage(int trackingNumber, const std::string& senderName, const std::string& senderAddress,
        const std::string& receiverName, const std::string& receiverAddress, double weight,
        double costPerUnitWeight, double flatFee);

    // manipulating Package functions
    Package* findPackage(int trackingNumber);
    double getPackageCost(int trackingNumber);
    std::string getPackageLabel(int trackingNumber);
    bool updatePackageStatus(int trackingNumber);

    // viewing functions
    std::vector<Package*> getAllPackages() const;
    std::vector<OneDayPackage*> getOneDayPackages() const;
    std::vector<TwoDayPackage*> getTwoDayPacakges() const;

private:
    std::vector<Employee*> employees;
    std::vector<Package*> packages;
};

#endif // POSTALSYSTEM_H
