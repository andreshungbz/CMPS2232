#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package {
public:
    // constructor
    Package(int trackingNumber, const std::string& senderName, const std::string& senderAddress,
        const std::string& receiverName, const std::string& receiverAddress, double weight,
        double costPerUnitWeight, double flatFee);

    // destructor
    virtual ~Package() = default;

    // getters
    int getTrackingNumber() const;
    std::string getShippingMethod() const;
    std::string getStatus() const;
    std::string getSenderName() const;
    std::string getSenderAddress() const;
    std::string getReceiverName() const;
    std::string getReceiverAddress() const;
    double getWeight() const;
    double getCostPerUnitWeight() const;
    double getFlatFee() const;

    // setters
    void setTrackingNumber(int trackingNumber);
    void setShippingMethod(const std::string& shippingMethod);
    void setStatus(const std::string& status);
    void setSenderName(const std::string& senderName);
    void setSenderAddress(const std::string& senderAddress);
    void setReceiverName(const std::string& receiverName);
    void setReceiverAddress(const std::string& receiverAddress);
    void setWeight(double weight);
    void setCostPerUnitWeight(double costPerUnitWeight);
    void setFlatFee(double flatFee);

    // member functions
    virtual double calculateCost() const;
    virtual void printLabel() const;
    bool updateStatus();

private:
    int m_trackingNumber;
    std::string m_shippingMethod;
    std::string m_status;
    std::string m_senderName;
    std::string m_senderAddress;
    std::string m_receiverName;
    std::string m_receiverAddress;
    double m_weight;
    double m_costPerUnitWeight;
    double m_flatFee;
};

#endif // PACKAGE_H
