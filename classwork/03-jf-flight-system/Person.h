#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    // constructor
    Person(const std::string& name, const std::string& nationality, const std::string& passportNumber);

    // destructor
    virtual ~Person() = default;

    // getters
    std::string getName() const;
    std::string getNationality() const;
    std::string getPassportNumer() const;

    // setters
    void setName(const std::string& name);
    void setNationality(const std::string& nationality);
    void setPassportNumber(const std::string& passportNumber);

    // virtual functions
    virtual void display() const = 0;
protected:
    void printDetails() const;
private:
    std::string m_name;
    std::string m_nationality;
    std::string m_passportNumber;
};



#endif // PERSON_H
