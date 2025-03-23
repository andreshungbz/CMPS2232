#ifndef CONTRACTOR_H
#define CONTRACTOR_H

#include "Employee.h"
#include <string>

class Contractor: public Employee {
public:
    Contractor(int id, const std::string& name, int salary, int contractDuration);
    ~Contractor() override = default;

    [[nodiscard]] int getContractDuration() const;
    void setContractDuration(int contractDuration);

    void print() const override;

private:
    int m_contractDuration;
};



#endif // CONTRACTOR_H
