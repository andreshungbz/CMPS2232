#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include <string>
#include "Employee.h"

class CommissionEmployee : public Employee {
public:
    CommissionEmployee(const std::string&, const std::string&, const std::string&, double = 0.0, double = 0.0);
    virtual ~CommissionEmployee() = default;

    void setCommissionRate(double);
    double getCommissionRate() const;

    void setGrossSales(double);
    double getGrossSales() const;

    virtual double earnings() const override;
    virtual std::string toString() const override;
private:
    double grossSales;
    double commissionRate;
};



#endif // COMMISSIONEMPLOYEE_H
