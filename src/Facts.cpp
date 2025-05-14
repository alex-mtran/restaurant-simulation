#include "../lib/Facts.hpp"

Facts::Facts(){
    this->ingredientFacts = std::vector<IngredientFacts>();
    this->ingredientFacts.push_back(IngredientFacts("CHICKEN", 14));
    this->ingredientFacts.push_back(IngredientFacts("DOUGH", 7));
    this->ingredientFacts.push_back(IngredientFacts("FETTUCCINE", 30));
    this->ingredientFacts.push_back(IngredientFacts("GREENS", 7));
    this->ingredientFacts.push_back(IngredientFacts("MEATBALL", 14));
    this->ingredientFacts.push_back(IngredientFacts("MOZZARELLA", 60));
    this->ingredientFacts.push_back(IngredientFacts("PARMESAN", 14));
    this->ingredientFacts.push_back(IngredientFacts("PEPPERONI", 30));
    this->ingredientFacts.push_back(IngredientFacts("PESTO", 14));
    this->ingredientFacts.push_back(IngredientFacts("SAUCE_ALFREDO", 21));
    this->ingredientFacts.push_back(IngredientFacts("SAUCE_MARINARA", 21));
    this->ingredientFacts.push_back(IngredientFacts("SAUCE_PARMESAN", 21));
    this->ingredientFacts.push_back(IngredientFacts("SAUCE_TOMATO", 21));
    this->ingredientFacts.push_back(IngredientFacts("SAUCE_SECRET", 21));
    this->ingredientFacts.push_back(IngredientFacts("SOUTHWESTDRESSING", 14));
    this->ingredientFacts.push_back(IngredientFacts("SHRIMP", 7));
    this->ingredientFacts.push_back(IngredientFacts("SPAGHETTI", 60));
    this->ingredientFacts.push_back(IngredientFacts("TOMATO", 21));
}

const int Facts::numOfIngredients(){
    return this->ingredientFacts.size();
}

IngredientFacts Facts::getIngredientFacts(INGREDIENT type){
    return this->ingredientFacts.at(type);
}