#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    // constructor
    Product(int id, const std::string& name, const std::string& description, int price, int quantity);

    // getters
    int getID() const { return m_id; }
    std::string getName() const { return m_name; }
    std::string getDescription() const { return m_description; }
    std::string getPrice() const;
    int getQuantity() const { return m_quantity; }

    // setters
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setPrice(int price);
    void setQuantity(int quantity);

    // other
    void display() const;
private:
    int m_id;
    std::string m_name;
    std::string m_description;
    int m_price;
    int m_quantity{1};
};

#endif // PRODUCT_H
