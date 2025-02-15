#ifndef PILOT_H
#define PILOT_H

#include "Person.h"
#include <vector>

class Pilot: public Person {
public:
    // constructor
    Pilot(const std::string& name, const std::string& nationality, const std::string& passportNumber,
            int flightHours, const std::vector<std::string>& spokenLangauges);

    // destructor
    virtual ~Pilot() = default;

    // getters
    int getFlightHours() const;
    std::vector<std::string> getSpokenLanguages() const;

    // setters
    void setFlightHours(int flightHours);

    // member functions
    void addSpokenLanguage(const std::string& language);
    bool removeSpokenLanguage(const std::string& language);
    bool speaksLanguage(const std::string& language);

    // pure virtual functions
    void display() const override;
private:
    int m_flightHours;
    std::vector<std::string> m_spokenLanguages;
};



#endif // PILOT_H
