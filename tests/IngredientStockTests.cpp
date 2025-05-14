// written by Scott Gonzalez Barrios - sgonz266
#include "gtest/gtest.h"
#include "../lib/Facts.hpp"
#include "../lib/IngredientStock.hpp"
#include <iostream>

TEST(IngredientStockTests, ReadWriteTest){
    IngredientStock* ingredientStock = new IngredientStock();
    IngredientStock* backup = new IngredientStock();
    ingredientStock->use(ingredientStock->get(0));
    ingredientStock->writeToFile(); // manipulates file for next constructors
    IngredientStock* test = new IngredientStock();
    ASSERT_NE(backup->str(), test->str());
    delete ingredientStock;
    delete test;
    delete backup; // reverts to original
}
