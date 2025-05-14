// Written by Scott Gonzalez Barrios - sgonz266
#ifndef __DATE_H__
#define __DATE_H__
#include <string>
#include <memory>
#include <ctime>

namespace Date{
    class Date{
    private:
        int day, month, year;
    protected:
    public:
        // Will initialize member variables with current date
        Date();
        // Parameter: (lifespan)
        Date(unsigned);
        // Parameters: (month, day, year)
        Date(unsigned, unsigned, unsigned);
        // Returns string formatted mm/dd/yy
        const std::string str() const;
        // Will return if the date is valid
        const bool is_valid() const;
        // Will determine if LHS is before or the same date as RHS.
        const bool operator<=(const Date&) const;
    };
}

#endif