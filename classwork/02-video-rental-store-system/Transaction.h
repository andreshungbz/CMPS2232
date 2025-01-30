#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <chrono>
#include <string>

class Transaction {
public:
    // constructor
    Transaction(int id, int customerID, int rentalItemID, int day, int month,
        int year, int duration, int charge, bool fulfilled, bool late);

    // setters
    void setID(int id);
    void setCustomerID(int id);
    void setRentalItemID(int id);
    void setRentStartDate(int day, int month, int year);
    void setRentalDuration(int duration);
    void setRentalCharge(int charge);
    void setFulfilled(bool fulfilled);
    void setLate(bool late);

    // getters
    int getID() const;
    int getCustomerID() const;
    int getRentalItemID() const;
    std::string getRentalStartDate() const;
    int getRentalDuration() const;
    int getRentalCharge() const;
    bool getFulfilled() const;
    bool getLate() const;

    // other member functions
    int calculateRentalCharge() const;
private:
    int m_id;
    int m_customerID;
    int m_rentalItemID;
    std::chrono::system_clock::time_point m_rentStartDate;
    int m_rentalDuration;
    int m_rentalCharge;
    bool m_fulfilled;
    bool m_late;
};



#endif // TRANSACTION_H
