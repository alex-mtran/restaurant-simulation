// written by Scott Gonzalez Barrios - sgonz266
#include "../lib/IngredientStock.hpp"
#include "../lib/User.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void getDate(std::string date, int* dates){
    dates[0] = stoi(date.substr(0,2));
    dates[1] = stoi(date.substr(3,5));
    dates[2] = stoi(date.substr(6));
}

IngredientStock::~IngredientStock(){
    this->writeToFile();
    for(unsigned i = 0; i < this->stock.size(); i++)
        delete this->stock.at(i);
}

IngredientStock::IngredientStock() : file("files/IngredientFile.txt"){
    std::ifstream input(PATH::getPath(this->file));
    std::string line, name, section;
    int inUse;
    Date::Date date, current;
    int dates[3];
    if(input.is_open()){
        while(getline(input, line)){
            std::stringstream ss(line);
            if(ss >> section) // collects name
                name = section;
            if (ss >> section) // collects date
                getDate(section, dates);
            date = Date::Date(dates[0], dates[1], dates[2]);
            current = Date::Date();
            if(date.is_valid() && current <= date)
                this->stock.push_back(new Ingredient(name,date));
        }
    }
    input.close();
}

std::string IngredientStock::str(){
    Ingredient* ingredient;
    std::string output = "Ingredients:\n";
    std::stringstream ss(output);
    for(unsigned i = 0; i < stock.size(); i++)
        ss << (i+1) << ") " << stock.at(i)->str() << "\n";
    return ss.str();
}

void IngredientStock::use(Ingredient* ingredient){
    for(unsigned i = 0; i < this->stock.size(); i++){
        if(ingredient == this->stock.at(i)){
            delete this->stock.at(i);
            this->stock.erase(this->stock.begin() + i);
        }
    }
}

void IngredientStock::use(std::vector<Ingredient*> &vec){
    for(Ingredient* ingredient : vec)
        this->use(ingredient);
}

void IngredientStock::add(Ingredient* ingredient){
    this->stock.push_back(ingredient);
}

void IngredientStock::writeToFile() const{
    std::ofstream output(PATH::getPath(this->file), std::ofstream::trunc);
    if(output.is_open()){
        for(unsigned i = 0; i < this->stock.size(); i++){
            if(this->stock.at(i)->isInUse())
                continue;
            output << this->stock.at(i)->str();
            if(i + 1 < this->stock.size())
                output << "\n";
        }
    }
    output.close();
}

Ingredient* IngredientStock::get(int i) const{
    return this->stock.at(i);
}

void IngredientStock::reserve(Ingredient* ingredient){
    ingredient->setUseStatus(true);
}

void IngredientStock::reserve(std::vector<Ingredient*> &set){
    for(Ingredient* ingredient : set)
        this->reserve(ingredient);
}

void IngredientStock::unreserve(Ingredient* ingredient){
    ingredient->setUseStatus(false);
}

const unsigned IngredientStock::size() const{
    return this->stock.size();
}

Ingredient* IngredientStock::getForUse(INGREDIENT type) const{
    for(Ingredient* ingredient : this->stock){
        if(type == ingredient->getType() && !ingredient->isInUse())
            return ingredient;
    }
    return nullptr;
}
