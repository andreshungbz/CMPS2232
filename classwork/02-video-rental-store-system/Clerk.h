#ifndef CLERK_H
#define CLERK_H

#include <string>
#include "RentalSystem.h"

class Clerk {
public:
    // constructor
    Clerk(int id, const std::string& fName, const std::string& lName,
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
    bool addCustomer(RentalSystem& rs, const std::string& fName, const std::string& lName,
        const std::string& address, const std::string& phone);
    bool rentItem(RentalSystem& rs, int c_id, int i_id);
    bool returnItem(RentalSystem& rs, int t_id);
    void generateSystemReport(RentalSystem& rs) const;
private:
    std::string m_employeeID;
    std::string m_firstName;
    std::string m_lastName;
    std::string m_address;
    std::string m_phone;
};



#endif // CLERK_H
