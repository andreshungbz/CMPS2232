#ifndef CARGOFLIGHT_H
#define CARGOFLIGHT_H

#include "Flight.h"

class CargoFlight: public Flight {
public:
    // constructor
    CargoFlight(const std::string& flightNumber, int duration, Airport* departingAirport, Airport* arrivingAirport,
        const std::vector<Passenger>& passengerList, const Pilot& pilot, const Aircraft* aircraft,
        int loadInTons, double costPerTon);

    // destructor
    virtual ~CargoFlight() = default;

    // getters
    int getLoadInTons() const;
    double getCostPerTon() const;

    // setters
    void setLoadInTons(int loadInTons);
    void setCostPerTon(double costPerTon);

    // virtual function overrides
    void display() const override;
    double calcRevenue() const override;
private:
    int m_loadInTons;
    double m_costPerTon;
};



#endif // CARGOFLIGHT_H
