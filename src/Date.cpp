// Written by Scott Gonzalez Barrios - sgonz266
#include "../lib/Date.hpp"
#include <ctime>
#include <string>
#include <sstream>

const bool isLeapYear(unsigned year){
    if (year % 400 == 0) 
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0) 
        return true;
    else 
        return false;
}

Date::Date::Date(){
    std::time_t current = std::time(0);
    std::tm* time = std::localtime(&current);
    this->year = time->tm_year + 1900;
    this->month = time->tm_mon + 1;
    this->day = time->tm_mday;
}

// Adds number of days in argument to current date
Date::Date::Date(unsigned days) : Date(){
    int validDates[] = {31,(isLeapYear(this->year) ? 29 : 28),31,30,31,30,31,31,30,31,30,31};
    this->day += days;
    while(this->day > validDates[this->month - 1]){
        this->day -= validDates[this->month - 1]; // subtracts days in respective month
        this->month++; // goes to next month for check
        if(this->month >= 13){ // next year
            this->month -= 12;
            this->year++;
            validDates[1] = isLeapYear(this->year) ? 29 : 28;
        }
    }
}

Date::Date::Date(unsigned month, unsigned day, unsigned year) : month(month), day(day), year(year){}

const bool Date::Date::operator<=(const Date &rhs) const{
    if(this->year > rhs.year) return false;
    if(this->year == rhs.year && this->month > rhs.month) return false;
    if(this->year == rhs.year && this->month == rhs.month && this->day > rhs.day) return false;
    return true;
}

const bool Date::Date::is_valid() const{
    if(this->month > 12 || this->month == 0)
        return false;
    int validDates[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(this->month == 2 && this->day == 29)
        return !isLeapYear(this->year);
    else
        return this->day <= validDates[this->month - 1];
}

const std::string Date::Date::str() const{
    std::string str = "", year = "";
    std::stringstream ss(str), yearSS(year);
    unsigned yearLocal = this->year;
    for(unsigned i = 1000; i > yearLocal; yearLocal *= 10)
        yearSS << "0";
    yearSS << this->year << "";
    ss << (this->month < 10  ? "0" : "") << this->month << "/" << (this->day < 10  ? "0" : "") << this->day << "/" << yearSS.str();
    return ss.str();
}
