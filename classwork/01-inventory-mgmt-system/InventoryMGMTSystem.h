#ifndef INVENTORY_MGMT_SYSTEM_H
#define INVENTORY_MGMT_SYSTEM_H

#include <string>
#include <unordered_map>
#include "Inventory.h"

class InventoryMGMTSystem {
public:
    // constructor
    explicit InventoryMGMTSystem(const std::string& name);
    // destructor
    ~InventoryMGMTSystem();

    // getters
    std::string getName() const { return m_name; };
    int getInventoryCount() const { return m_inventoryCount; };

    // setters
    void setName(const std::string& name);

    // other
    void addInventory(const std::string& name);
    bool removeInventory(const std::string& name);
    void renameInventory(const std::string& name);
    void display() const;
private:
    std::string m_name;
    std::unordered_map<std::string, Inventory> m_inventories;
    int m_inventoryCount{0};
    int m_nextID{1};
};

#endif // INVENTORY_MGMT_SYSTEM_H
