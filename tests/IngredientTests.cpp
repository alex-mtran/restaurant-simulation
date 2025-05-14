#include "gtest/gtest.h"
#include "../lib/Ingredient.hpp"


TEST(IngredientTests, ConstructStringTest){
    Date::Date date = Date::Date(9,9,2099);
    Ingredient ing = Ingredient("DOUGH", date);
    EXPECT_EQ(ing.str(), "DOUGH\t09/09/2099");
}

TEST(IngredientTests, SetUseStatusTest){
    Date::Date date = Date::Date(9,9,2099);
    Ingredient ing = Ingredient("DOUGH", date);
    ing.setUseStatus(false);
    EXPECT_FALSE(ing.isInUse());
    ing.setUseStatus(true);
    EXPECT_TRUE(ing.isInUse());
}

TEST(IngredientTests, GetTypeTest){
    Date::Date date = Date::Date(9,9,2099);
    Ingredient ing = Ingredient("DOUGH", date);
    EXPECT_EQ(ing.getType(), INGREDIENT::DOUGH);
    ing = Ingredient("CHICKEN", date);
    EXPECT_EQ(ing.getType(), INGREDIENT::CHICKEN);
}