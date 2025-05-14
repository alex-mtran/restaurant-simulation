//typed by Augustine Ayoub
// written by Scott Gonzalez Barrios - sgonz266

#ifndef __USER_HPP__
#define __USER_HPP__
#include <string>
#include <iostream>
#include <fstream> // needed for init menu
#include "Path.hpp"
using namespace std;


class User{
private:
protected:
    std::string username;
    std::string password;
    std::string ingredientFile;
    std::string menuFile;
    std::string menu;
    // will access respective menuFile and get menu
    std::string initMenu(std::string);
public:
    User();
    // parameters (name, password, ingredientFile)
    User(std::string, std::string, std::string);
    ~User();
    // will verify if argument is same as username stored
    bool verifyUsername(std::string);
    // will verify if argument is same as password stored
    bool verifyPassword(std::string);
    virtual std::string getMenu() = 0;
};

#endif
