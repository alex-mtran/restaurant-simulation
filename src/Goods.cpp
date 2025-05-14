//written by augustine ayoub

#include "../lib/Goods.hpp"

using namespace std;

Goods::Goods(){}

Goods::Goods(const string name, double price) : name(name), price(price){}

Goods::Goods(const string name, double price, const vector<Ingredient*> &ingredients) : name(name), price(price){
    for(Ingredient* ingredient : ingredients)
        this->myIngredients.push_back(ingredient);
}

const string Goods::getName() const {
    return name;
}

void Goods::setName(string n) {
    name = n;
}

const double Goods::getPrice() const {
    return price;
}

void Goods::setPrice(double d) {
    price = d;
}

string Goods::Ingredients() {
    string str = "";
    if(myIngredients.size() == 0)
        return "This good contains no individual ingredients.\n";
    //for loop should follow format of "1) pepperoni 02/10/2022"
    for (int i = 0; i < myIngredients.size(); ++i) {
        str.append((i+1) + ") " + myIngredients.at(i)->str() + "\n");
    }
    return str;
}

void Goods::unreserve(){
    for(Ingredient* ingredient : myIngredients)
        ingredient->setUseStatus(false);
}