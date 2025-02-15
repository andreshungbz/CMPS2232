#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>

#include "Aircraft.h"
#include "Passenger.h"
#include "Pilot.h"

class Airport;

class Flight {
public:
    // constructor
    Flight(const std::string& flightNumber, int duration, Airport* departingAirport, Airport* arrivingAirport,
        const std::vector<Passenger>& passengerList, const Pilot& pilot, const Aircraft* aircraft);

    // destructor
    virtual ~Flight() = default;

    // getters
    std::string getFlightNumber() const;
    int getDuration() const;
    const Airport& getDepartingAirport() const;
    const Airport& getArrivingAirport() const;
    std::vector<Passenger> getPassengerList() const;
    Pilot getPilot() const;
    const Aircraft& getAircraft() const;

    // setters
    void setFlightNumber(const std::string& flightNumber);
    void setDuration(int duration);
    void setDepartingAirport(const Airport* departingAirport);
    void setArrivingAirport(const Airport* arrivingAirport);
    void setPassengerList(const std::vector<Passenger>& passengerList);
    void setPilot(const Pilot& pilot);
    void setAircraft(const Aircraft& aircraft);

    // member functions
    void addPassenger(const Passenger& passenger);
    bool removePassenger(const Passenger& passenger);
    bool isPassengerOnFlight(const Passenger& passenger);

    // virtual functions
    virtual void display() const = 0;
    virtual double calcRevenue() const = 0;
protected:
    void printDetails() const;
private:
    std::string m_flightNumber;
    int m_duration;
    Airport* m_departingAirport;
    Airport* m_arrivingAirport;
    std::vector<Passenger> m_passengerList;
    Pilot m_pilot;
    Aircraft* m_aircraft;
};



#endif // FLIGHT_H
