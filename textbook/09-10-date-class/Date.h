#include <string>

#ifndef DATE_H
#define DATE_H



class Date {
public:
    explicit Date(unsigned int = 1, unsigned int = 1, unsigned int = 2000);
    std::string toString() const;
private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
};



#endif //DATE_H
