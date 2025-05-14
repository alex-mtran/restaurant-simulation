// Written by Scott Gonzalez Barrios - sgonz266
#ifndef __INGREDIENT_HPP__
#define __INGREDIENT_HPP__
#include "Date.hpp"
#include <string>
#include <vector>
#include <fstream>

// enum of all possible ingredients (alphabetical order)
enum INGREDIENT{CHICKEN, DOUGH, FETTUCCINE, GREENS, MEATBALL, MOZZARELLA, PARMESAN, 
                PEPPERONI, PESTO, SAUCE_ALFREDO, SAUCE_MARINARA, 
                SAUCE_PARMESAN, SAUCE_TOMATO, SAUCE_SECRET, SOUTHWESTDRESSING,
                SHRIMP, SPAGHETTI, TOMATO};

struct IngredientFacts{
    IngredientFacts(std::string, unsigned);
    std::string name;
    // lifespan (in days) of an ingredient
    unsigned expTime;
};

class Ingredient{
private:
    std::string name;
    Date::Date expDate; // expiration date
    INGREDIENT type; // for knowing which type this is without having to compare strings
    bool inUse;
    // inits this->type with correct type based on string
    void initType(std::string);
protected:
public:
    Ingredient();
    // Parameters: (name, expDate)
    Ingredient(std::string, Date::Date);
    // Return formatted string in format "name mm/dd/yyyy"
    const std::string str() const;
    // Will change availability status of this ingredient
    void setUseStatus(bool);
    // Will return inUse value
    bool isInUse();
    // Will return its type
    const INGREDIENT getType() const;
    const std::string getName() const;
};

#endif