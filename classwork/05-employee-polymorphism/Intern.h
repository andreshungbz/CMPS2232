#ifndef INTERN_H
#define INTERN_H

#include "Employee.h"
#include <string>

class Intern: public Employee {
public:
    Intern(int id, const std::string& name, int salary, Employee* mentor);
    ~Intern() override = default;

    [[nodiscard]] Employee* getMentor() const;
    void setMentor(Employee* mentor);

    void print() const override;

private:
    Employee* m_mentor;
};



#endif // INTERN_H
