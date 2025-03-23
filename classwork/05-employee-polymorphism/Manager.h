#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include <string>

class Manager: public Employee {
public:
    Manager(int id, const std::string& name, int salary, const std::string& department);
    ~Manager() override = default;

    [[nodiscard]] std::string getDepartment() const;
    void setDepartment(const std::string& department);

    void print() const override;

private:
    std::string m_department;
};



#endif // MANAGER_H
