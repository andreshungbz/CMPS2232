#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>

class Aircraft {
public:
    // constructor
    Aircraft(const std::string& model, const std::string& manufacturer, const std::string& code);

    // destructor
    virtual ~Aircraft() = default;

    // getters
    std::string getModel() const;
    std::string getManufacturer() const;
    std::string getCode() const;

    // setters
    void setModel(const std::string& model);
    void setManufacturer(const std::string& manufacturer);
    void setCode(const std::string& code);

    // virtual functions
    virtual void display() const = 0;
    virtual double calcFuelConsumption() const = 0;
protected:
    void printDetails() const;
private:
    std::string m_model;
    std::string m_manufacturer;
    std::string m_code;
};



#endif // AIRCRAFT_H
