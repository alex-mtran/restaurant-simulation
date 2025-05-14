// Written by Scott Gonzalez Barrios - sgonz266
#ifndef __FACTS_HPP__
#define __FACTS_HPP__
#include "Ingredient.hpp"

class Facts{
    public:
    std::vector<IngredientFacts> ingredientFacts;
    Facts();
    // Returns a struct containing the name and lifespan of an INGREDIENT
    IngredientFacts getIngredientFacts(INGREDIENT);
    // Returns how many possible ingredients there are
    const int numOfIngredients();
};

#endif