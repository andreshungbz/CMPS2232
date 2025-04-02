#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
    Employee(int id, const std::string& name, int salary);
    virtual ~Employee() = default;

    [[nodiscard]] int getID() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getSalary() const;

    void setID(int id);
    void setName(const std::string& name);
    void setSalary(int salary);

    virtual void print() const;

private:
    int m_id;
    std::string m_name;
    int m_salary;
};



#endif // EMPLOYEE_H
