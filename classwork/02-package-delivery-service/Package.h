#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package {
public:
    // constructors
    Package();
    Package(double weight, double cost, const std::string& sName, const std::string& sZip,
        const std::string& rName, const std::string& rZip);

    // destructor
    virtual ~Package() = default;

    // getters
    double getWeigthInOunce() const;
    double getCostPerOunce() const;
    std::string getSenderName() const;
    std::string getSenderZip() const;
    std::string getRecipientName() const;
    std::string getRecipientZip() const;

    // setters
    void setWeightInOunce(double weight);
    void setCostPerOunce(double cost);
    void setSenderName(const std::string& sName);
    void setSenderZip(const std::string& sZip);
    void setRecipientName(const std::string& rName);
    void setRecipientZip(const std::string& rZip);

    virtual double calcCost() const;
    virtual void print() const;
protected:
    void printDetails() const;
private:
    double weightInOunce;
    double costPerOunce;
    std::string senderName;
    std::string senderZip;
    std::string recipientName;
    std::string recipientZip;
};



#endif // PACKAGE_H
