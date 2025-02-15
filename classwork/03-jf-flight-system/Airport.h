#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <vector>
#include "Flight.h"

class Airport {
public:
    // constructor
    Airport(const std::string& airportID, const std::string& name, const std::string& country,
        const std::vector<Flight*>& departingFlights, const std::vector<Flight*>& arrivingFlights);

    // destructor
    virtual ~Airport();

    // getters
    std::string getAirportID() const;
    std::string getName() const;
    std::string getCountry() const;

    // setters
    void setAirportID(const std::string& aiportID);
    void setName(const std::string& name);
    void setCountry(const std::string& country);

    // member functions
    void addDepartingFlight(const Flight& departingFlight);
    void addArrivingFlight(const Flight& arrivingFlight);
    bool removeDepartingFlight(const Flight& departingFlight);
    bool removeArrivingFlight(const Flight& arrivingFlight);
    bool flightExists(const std::string& flightNumber);
private:
    std::string m_airportID;
    std::string m_name;
    std::string m_country;
    std::vector<Flight*> m_departingFlights;
    std::vector<Flight*> m_arrivingFlights;
};



#endif // AIRPORT_H
