#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
    // constructor
    Employee(int employeeID, const std::string& name, const std::string& password);

    // getters
    int getEmployeeID() const;
    std::string getName() const;
    std::string getPassword() const;

    // setters
    void setEmployeeID();
    void setName();
    void setPassword();

private:
    int m_employeeID;
    std::string m_name;
    std::string password;
};

#endif // EMPLOYEE_H
