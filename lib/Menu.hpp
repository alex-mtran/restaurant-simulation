//Written by Alexander Tran - atran388
#ifndef __MENU_HPP
#define __MENU_HPP_
#include "Customer.hpp"
#include "User.hpp"
#include "AdminLogistics.hpp"
#include "AdminStatus.hpp"
#include "Ingredient.hpp"
#include "IngredientStock.hpp"
#include "Facts.hpp"
#include <iostream>
#include <ctype.h>
#include <stdio.h>

using namespace std;

namespace FOODMENU {
    //Helper functions
    bool checkIngredientsStock(string, IngredientStock*);
    void addIngredients(string, vector<Ingredient*>&, IngredientStock*);

    //Customer menu options
    string printFoodMenu();
    void addToCart(string, Customer&, IngredientStock*); //(2)
}

string capsOn(string &str);

namespace ADMINMENU{
    // helper
    int verifyInput(int, int); // (input, max)
}

#endif
