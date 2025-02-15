#ifndef AIRLINER_H
#define AIRLINER_H

#include "Aircraft.h"

class Airliner: public Aircraft{
public:
    // constructor
    Airliner(const std::string& model, const std::string& manufacturer, const std::string& code,
        int passengerCapacity);

    // destructor
    virtual ~Airliner() = default;

    // getters
    int getPassengerCapacity() const;

    // setters
    void setPassengerCapacity(int passengerCapacity);

    // virtual function overrides
    void display() const override;
    double calcFuelConsumption() const override;
private:
    int m_passengerCapacity;
};



#endif // AIRLINER_H
