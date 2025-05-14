//Written by Alexander Tran - atran388
#include "gtest/gtest.h"
#include "../lib/main.hpp"
#include <iostream>

TEST(MainTests, CapsOnWord) {
    string word = "wOrD";

    EXPECT_EQ(capsOn(word), "WORD");
}

TEST(MainTests, CapsOnSentence) {
    string sentence = "ThIs SentEncE";

    EXPECT_EQ(capsOn(sentence), "THIS SENTENCE");
}

TEST(MainTests, CapsOnNumberGibberish) {
    string gibberish = "12343124932157";

    EXPECT_EQ(capsOn(gibberish), "12343124932157");
}

TEST(MainTests, AddToCartFood) {
    Customer customer = Customer();
    IngredientStock ingredientStock = IngredientStock();
    FOODMENU::addToCart("CHEESE PIZZA", customer, ingredientStock);
    
    EXPECT_EQ(customer.viewCart(), "1\tCHEESE PIZZA $25.99\n");
}

TEST(MainTests, AddToCartDrink) {
    Customer customer = Customer();
    IngredientStock ingredientStock = IngredientStock();
    FOODMENU::addToCart("COKE", customer, ingredientStock);
    
    EXPECT_EQ(customer.viewCart(), "1\tCOKE $2.99\n");
}

TEST(MainTests, AddToCartMultipleFoods) {
    Customer customer = Customer();
    IngredientStock ingredientStock = IngredientStock();
    FOODMENU::addToCart("CHEESE PIZZA", customer, ingredientStock);
    FOODMENU::addToCart("CHICKEN PESTO", customer, ingredientStock);
    FOODMENU::addToCart("CHEESE PIZZA", customer, ingredientStock);

    EXPECT_EQ(customer.viewCart(), "2\tCHEESE PIZZA $25.99\n1\tCHICKEN PESTO $20.99\n");
}

TEST(MainTests, AddToCartMultipleDrinks) {
    Customer customer = Customer();
    IngredientStock ingredientStock = IngredientStock();
    FOODMENU::addToCart("COKE", customer, ingredientStock);
    FOODMENU::addToCart("COKE", customer, ingredientStock);

    EXPECT_EQ(customer.viewCart(), "2\tCOKE $2.99\n");
}

TEST(MainTests, IsNumStringOfNumbers) {
    string numberStr = "12348907321904";

    EXPECT_EQ(isNum(numberStr), 1);
}

TEST(MainTests, IsNumGibberish) {
    string gibberish = "1234abcd";

    EXPECT_EQ(isNum(gibberish), 0);
}

TEST(MainTests, IsNumWithSpaces) {
    string sentence = "Hello world!";

    EXPECT_EQ(isNum(sentence), 0);
}