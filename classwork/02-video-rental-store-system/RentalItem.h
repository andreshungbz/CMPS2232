#ifndef RENTALITEM_H
#define RENTALITEM_H

#include <string>

class RentalItem {
public:
    // constructor
    RentalItem(int id, const std::string& type, const std::string& name,
        int price, int count, bool available);

    // setters
    void setID(int id);
    void setType(const std::string& type);
    void setName(const std::string& name);
    void setPrice(int price);
    void setAvailable(bool available);

    // getters
    int getID() const;
    std::string getType() const;
    std::string getName() const;
    int getPrice() const;
    int getCount() const;
    bool getAvailable() const;

    // other member functions
    std::string print() const;
private:
    int m_id;
    std::string m_type;
    std::string m_name;
    int m_price;
    int m_count;
    bool m_available;
};



#endif // RENTALITEM_H
