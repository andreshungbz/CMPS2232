#ifndef PASSENGER_H
#define PASSENGER_H

#include "Person.h"

class Passenger: public Person {
public:
    // constructor
    Passenger(const std::string& name, const std::string& nationality, const std::string& passportNumber,
            int travelMiles, double ticketPrice);

    // destructor
    virtual ~Passenger() = default;

    // getters
    int getTravelMiles() const;
    double getTicketPrice() const;

    // setters
    void setTravelMiles(int travelMiles);
    void setTicketPrice(double ticketPrice);

    // virtual function overrides
    void display() const override;
private:
    int m_travelMiles;
    double m_ticketPrice;
};



#endif // PASSENGER_H
