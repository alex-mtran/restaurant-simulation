/written by augustine ayoub - aayou004
//Written by Alexander Tran - atran388
#include "../lib/Menu.hpp"
#include "gtest/gtest.h"

#include "gtest/gtest.h"
#include "../lib/Goods.hpp"
#include <iostream>

TEST(GoodsTest, IngredientsOfCheesePizza) {
    IngredientStock ingredientStock = IngredientStock();
    vector<Ingredient*> ingredients = vector<Ingredient*>();
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::DOUGH));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::MOZZARELLA));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::SAUCE_MARINARA));
    Goods* good = new Goods("CHEESE PIZZA", 25.99, ingredients);
    EXPECT_EQ(good->Ingredients(), "1) DOUGH\n2) MOZZARELLA\n3) SAUCE_MARINARA\n");
    delete good;
}

TEST(GoodsTest, IngredientsPepperoniPizza) {
    IngredientStock ingredientStock = IngredientStock();
    vector<Ingredient*> ingredients = vector<Ingredient*>();
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::DOUGH));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::MOZZARELLA));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::PEPPERONI));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::SAUCE_MARINARA));
    Goods* good = new Goods("PEPPERONI PIZZA", 25.99, ingredients);
    EXPECT_EQ(good->Ingredients(), "1) DOUGH\n2) MOZZARELLA\n3) PEPPERONI\n4) SAUCE_MARINARA\n");
    delete good;
}

TEST(GoodsTest, IngredientsComboPizza) {
    IngredientStock ingredientStock = IngredientStock();
    vector<Ingredient*> ingredients = vector<Ingredient*>();
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::DOUGH));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::MOZZARELLA));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::PEPPERONI));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::GREENS));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::TOMATO));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::SAUCE_MARINARA));
    Goods* good = new Goods("COMBO PIZZA", 26.99, ingredients);
    EXPECT_EQ(good->Ingredients(), "1) DOUGH\n2) MOZZARELLA\n3) PEPPERONI\n4) GREENS\n5) TOMATO\n6) SAUCE_MARINARA\n");
    delete good;
}

TEST(GoodsTest, IngredientsShrimpPasta) {
    IngredientStock ingredientStock = IngredientStock();
    vector<Ingredient*> ingredients = vector<Ingredient*>();
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::SHRIMP));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::FETTUCCINE));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::SAUCE_PARMESAN));
    Goods* good = new Goods("SHRIMP FETTUCCINE ALFREDO", 21.99, ingredients);
    EXPECT_EQ(good->Ingredients(), "1) SHRIMP\n2) FETTUCCINE\n3) SAUCE_PARMESAN\n");
    delete good;
}

TEST(GoodsTest, IngredientsSpaghettiPasta) {
    IngredientStock ingredientStock = IngredientStock();
    vector<Ingredient*> ingredients = vector<Ingredient*>();
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::SPAGHETTI));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::MEATBALL));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::SAUCE_MARINARA));
    Goods* good = new Goods("SPAGHETTI AND MEATBALLS", 19.99, ingredients);
    EXPECT_EQ(good->Ingredients(), "1) SPAGHETTI\n2) MEATBALL\n3) SAUCE_MARINARA\n");
    delete good;
}

TEST(GoodsTest, IngredientsChickenPasta) {
    IngredientStock ingredientStock = IngredientStock();
    vector<Ingredient*> ingredients = vector<Ingredient*>();
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::CHICKEN));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::PESTO));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::SPAGHETTI));
    Goods* good = new Goods("CHICKEN PESTO", 20.99, ingredients);
    EXPECT_EQ(good->Ingredients(), "1) CHICKEN\n2) PESTO\n3) SPAGHETTI\n");
    delete good;
}

TEST(GoodsTest, IngredientsHouseSalad) {
    IngredientStock ingredientStock = IngredientStock();
    vector<Ingredient*> ingredients = vector<Ingredient*>();
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::GREENS));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::TOMATO));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::SAUCE_SECRET));
    Goods* good = new Goods("HOUSE SALAD", 12.99, ingredients);
    EXPECT_EQ(good->Ingredients(), "1) GREENS\n2) TOMATO\n3) SAUCE_SECRET\n");
    delete good;
}

TEST(GoodsTest, IngredientsSouthwestSalad) {
    IngredientStock ingredientStock = IngredientStock();
    vector<Ingredient*> ingredients = vector<Ingredient*>();
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::GREENS));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::MOZZARELLA));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::TOMATO));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::SOUTHWESTDRESSING));
    Goods* good = new Goods("SOUTHWEST COBB SALAD", 11.99, ingredients);
    EXPECT_EQ(good->Ingredients(), "1) GREENS\n2) MOZZARELLA\n3) TOMATO\n4) SOUTHWESTDRESSING\n");
    delete good;
}

TEST(GoodsTest, IngredientsChickenSalad) {
    IngredientStock ingredientStock = IngredientStock();
    vector<Ingredient*> ingredients = vector<Ingredient*>();
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::GREENS));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::MOZZARELLA));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::CHICKEN));
    ingredients.push_back(ingredientStock.getForUse(INGREDIENT::SAUCE_SECRET));
    Goods* good = new Goods("CHICKEN CAESAR SALAD", 13.99, ingredients);
    EXPECT_EQ(good->Ingredients(), "1) GREENS\n2) MOZZARELLA\n3) CHICKEN\n4) SAUCE_SECRET\n");
    delete good;
}