// written by Scott Gonzalez Barrios - sgonz266
#include "../lib/Ingredient.hpp"
#include "../lib/Facts.hpp"

Ingredient::Ingredient(){
    this->name = "";
    this->inUse = false;
}

Ingredient::Ingredient(std::string name, Date::Date expDate) :
    name(name), expDate(expDate), inUse(false){
    initType(name);
    // FACTS::initFacts(); done in AdminLogistics
}

void Ingredient::initType(std::string type){
    Facts ingredientFacts = Facts();
    for(unsigned i = 0; i < ingredientFacts.numOfIngredients(); i++){
        if(ingredientFacts.getIngredientFacts(static_cast<INGREDIENT>(i)).name == type){
            this->type = static_cast<INGREDIENT>(i);
            break;
        }
    }
}

bool Ingredient::isInUse(){
    return this->inUse;
}

void Ingredient::setUseStatus(bool status){
    this->inUse = status;
}

const std::string Ingredient::str() const{
    return this->name + "\t" + this->expDate.str();
}

const INGREDIENT Ingredient::getType() const{
    return this->type;
}

IngredientFacts::IngredientFacts(std::string name, unsigned time){
    this->name = name;
    this->expTime = time;
}

const std::string Ingredient::getName() const{
    return this->name;
}