#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include <string>
#include <unordered_map>
#include <vector>
#include "Customer.h"
#include "RentalItem.h"
#include "Transaction.h"

class RentalSystem {
public:
    // constructor
    RentalSystem() = default;

    // member functions
    std::string displayRentalItems() const;
    std::string displayCustomers() const;
    std::string displayTransactions() const;
    std::string getRentalItemDetails(int id) const;
    std::string getCustomerDetails(int id) const;
    Transaction* findTransaction(int id);
private:
    std::unordered_map<int, Customer*> customers;
    std::unordered_map<int, RentalItem*> rentalItems;
    std::vector<Transaction*> transactions;
};



#endif // RENTALSYSTEM_H
