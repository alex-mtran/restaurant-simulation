// written by Scott Gonzalez Barrios - sgonz266

#ifndef __ADMINSTATUS_HPP__
#define __ADMINSTATUS_HPP__
#include "User.hpp"

class AdminStatus : public User{
private:
    int status;
    std::string statusFile;
    // Sets the status of the restaurant (open, closed, etc.)
    void setStatus(int);
protected:
public:
    AdminStatus();
    ~AdminStatus();
    // Will check the current status of the restaurant from file
    int statusInit();
    // Retrieves the status of the restaurant
    int getStatus();
    // Opens restaurant
    void open(); // status = 1
    // Temp closes restaurant
    void close(); // status = 2
    // Permenantly closes restaurant
    void closePerm(); // status = 3
    virtual std::string getMenu() override;
};

#endif