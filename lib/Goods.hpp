#ifndef __GOODS_H__
#define __GOODS_H__
#include <vector>
#include "Ingredient.hpp"
#include <string>
#include <iostream>

using namespace std;

class Goods{
private:
    string name;
    double price;
    vector<Ingredient*> myIngredients; //switched naming so its not confusing making for loop
protected:
public:
    Goods();
    Goods(const string, double);
    Goods(const string, double, const vector<Ingredient*> &);
    const string getName() const;
    void setName(string);
    const double getPrice() const;
    void setPrice(double d);
    string Ingredients();
    void unreserve();
};

#endif