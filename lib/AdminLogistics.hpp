// written by Scott Gonzalez Barrios - sgonz266

#ifndef __ADMINLOGISTICS_HPP__
#define __ADMINLOGISTICS_HPP__
#include "User.hpp"
#include "Ingredient.hpp"
#include "IngredientStock.hpp"
#include "Date.hpp"
#include <vector>

class AdminLogistics : public User{
private:
protected:
public:
    // Initializes the ingredientFacts
    AdminLogistics();
    ~AdminLogistics();
    // Will add a fresh INGREDIENT to the IngredientStock
    void addToStock(IngredientStock *, INGREDIENT);
    virtual std::string getMenu() override;
};

#endif