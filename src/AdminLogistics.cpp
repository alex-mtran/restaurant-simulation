// written by Scott Gonzalez Barrios - sgonz266
#include "../lib/IngredientStock.hpp"
#include "../lib/AdminLogistics.hpp"
#include "../lib/Facts.hpp"

AdminLogistics::AdminLogistics() : User("admin", "adminPassword", "files/AdminLogisticsMenu.txt"){
    this->menu = this->initMenu(this->menuFile);
}

AdminLogistics::~AdminLogistics(){
}

void AdminLogistics::addToStock(IngredientStock* stock, INGREDIENT type){
    Facts ingredientFacts = Facts();
    Date::Date date = Date::Date(ingredientFacts.getIngredientFacts(type).expTime);
    Ingredient* ingredient = new Ingredient(ingredientFacts.getIngredientFacts(type).name, date);
    stock->add(ingredient);
}

std::string AdminLogistics::getMenu(){
    return "AdminLogisitics's menu:\n" + this->menu;
}