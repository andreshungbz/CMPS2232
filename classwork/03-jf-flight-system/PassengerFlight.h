#ifndef PASSENGERFLIGHT_H
#define PASSENGERFLIGHT_H

#include "Flight.h"

class PassengerFlight: public Flight {
public:
    // constructor
    PassengerFlight(const std::string& flightNumber, int duration, Airport* departingAirport, Airport* arrivingAirport,
        const std::vector<Passenger>& passengerList, const Pilot& pilot, const Aircraft* aircraft);

    // destructor
    virtual ~PassengerFlight() = default;

    // virtual function overrides
    void display() const override;
    double calcRevenue() const override;
};



#endif // PASSENGERFLIGHT_H
