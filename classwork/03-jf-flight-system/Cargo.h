#ifndef CARGO_H
#define CARGO_H

#include "Aircraft.h"

class Cargo: public Aircraft {
public:
    // constructor
    Cargo(const std::string& model, const std::string& manufacturer, const std::string& code,
        int loadCapacityInTons);

    // destructor
    virtual ~Cargo() = default;

    // getters
    int getLoadCapacityInTons() const;

    // setters
    void setLoadCapacityInTons(int loadCapacityInTons);

    // virtual function overrides
    void display() const override;
    double calcFuelConsumption() const override;
private:
    int m_loadCapacityInTons;
};



#endif // CARGO_H
