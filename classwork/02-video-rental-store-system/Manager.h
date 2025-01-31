#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "RentalSystem.h"

class Manager {
public:
    // constructor
    Manager(int id, const std::string& fName, const std::string& lName,
        const std::string& address, const std::string& phone);

    // setters
    void setEmployeeID(int id);
    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setAddress(const std::string& address);
    void setPhone(const std::string& phone);

    // getters
    int getEmployeeID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getAddress() const;
    std::string getPhone() const;

    // other member functions
    std::string toString() const;
    bool deleteCustomer(RentalSystem& rs, int c_id);
    bool addItem(RentalSystem& rs, const std::string& type, const std::string& name, int price, int count);
    bool deleteItem(RentalSystem& rs, int i_id);
private:
    std::string m_employeeID;
    std::string m_firstName;
    std::string m_lastName;
    std::string m_address;
    std::string m_phone;
};



#endif // MANAGER_H
