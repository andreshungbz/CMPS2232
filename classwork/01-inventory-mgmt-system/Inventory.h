#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <unordered_map>
#include "Product.h"

class Inventory {
public:
    // constructor
    Inventory(int id, const std::string& name);
    // destructor
    ~Inventory();

    // getters
    int getID() const { return m_id; };
    std::string getName() const { return m_name; };
    int getProductsCount() const { return m_productCount; };

    // setters
    void setName(const std::string& name);

    // other
    Product* findProduct(int id);
    void addProduct();
    bool removeProduct(int id);
    bool updateProduct(int id);
    void display() const;
private:
    int m_id;
    std::string m_name;
    std::unordered_map<int, Product*> m_products;
    int m_productCount{0};
    int m_nextID{1};
};

#endif // INVENTORY_H
