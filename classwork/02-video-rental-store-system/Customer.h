#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    // constructor
    Customer(int id, const std::string& fName, const std::string& lName,
        const std::string& address, const std::string& phone);

    // setters
    void setID(int id);
    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setAddress(const std::string& address);
    void setPhone(const std::string& phone);

    // getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getAddress() const;
    std::string getPhone() const;

    // other member functions
    std::string print() const;
private:
    int m_id;
    std::string m_firstName;
    std::string m_lastName;
    std::string m_address;
    std::string m_phone;
};



#endif // CUSTOMER_H
