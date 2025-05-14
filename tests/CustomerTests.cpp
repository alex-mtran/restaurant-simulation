// written by Scott Gonzalez Barrios - sgonz266
// written by augustine ayoub - aayou004
#include "gtest/gtest.h"
#include "../lib/Customer.hpp"
#include "../lib/Ingredient.hpp"
#include "../lib/Goods.hpp"
#include <iostream>
#include <string>

TEST(CustomerTests, ConstructTest){
    Customer customer = Customer();

    EXPECT_TRUE(customer.verifyUsername("customer"));
    EXPECT_FALSE(customer.verifyUsername("customerUser"));
    EXPECT_TRUE(customer.verifyPassword("customerPassword"));
    EXPECT_FALSE(customer.verifyPassword("customerPass"));
}

TEST(CustomerTests, MenuInitTest){
    std::ifstream menuFile("files/CustomerMenu.txt");
    ASSERT_TRUE(menuFile.is_open());
    std::string menu = "";
    std::string line = "";
    while(getline(menuFile, line))
        menu.append(line + "\n");
    Customer customer = Customer();
    ASSERT_EQ(customer.getMenu(), "Welcome to Al Dente Amore!\n" + menu);
    menuFile.close();
}

TEST(CustomerTests, AddItemTest) {
    Customer customer = Customer();
    Goods* good = new Goods("CHEESE PIZZA", 25.99);
    customer.addItem(good);
    EXPECT_TRUE(customer.numOfItemInCart("CHEESE PIZZA") == 1);
    // delete good done in customer destructor
}

TEST(CustomerTests, RemoveOneItem) { //testing to see if remove works on normal cart
    Customer customer = Customer();
    Goods* good = new Goods("CHEESE PIZZA", 25.99);
    customer.addItem(good);
    Goods* good1 = new Goods("COMBO PIZZA", 26.99);
    customer.addItem(good1);
    Goods* good2 = new Goods("COMBO PIZZA", 26.99);
    customer.addItem(good2);
    customer.removeItem("CHEESE PIZZA");
    EXPECT_TRUE(customer.numOfItemInCart("COMBO PIZZA") == 2);
    // delete good;
    // delete good1;
    // delete good2;
    // done in customer destructor
}

TEST(CustomerTests, RemoveEmpty) { //testing to see if remove works on empty cart
    Customer customer = Customer();
    customer.removeItem("CHEESE PIZZA");
    EXPECT_FALSE(customer.numOfItemInCart("CHEESE PIZZA") == 1);
}

TEST(CustomerTests, RemoveDuplicates) { //testing to see if remove works on duplicate items
    Customer customer = Customer();
    Goods* good = new Goods("COMBO PIZZA", 26.99);
    customer.addItem(good);
    Goods* good1 = new Goods("COMBO PIZZA", 26.99);
    customer.addItem(good1);
    customer.removeItem("COMBO PIZZA");
    EXPECT_TRUE(customer.numOfItemInCart("COMBO PIZZA") == 1);
    // delete good;
    // delete good1;
    // done in destructor
}

TEST(CustomerTests, OneItemInCart) {
    Customer customer = Customer();
    Goods* good = new Goods("COMBO PIZZA", 26.99);
    Goods* expectedResult = good;
    customer.addItem(good);
    EXPECT_EQ(customer.itemInCart("COMBO PIZZA"), expectedResult);
    // delete good; done in destructor
}

TEST(CustomerTests, NumberOfItems) {
    Customer customer = Customer();
    Goods* good1 = new Goods("COMBO PIZZA", 26.99);
    customer.addItem(good1);
    Goods* good2 = new Goods("COMBO PIZZA", 26.99);
    customer.addItem(good2);
    Goods* good3 = new Goods("PEPPERONI PIZZA", 26.99);
    customer.addItem(good3);
    EXPECT_TRUE(customer.numOfItemInCart("COMBO PIZZA") == 2);
    // delete good1;
    // delete good2;
    // delete good3;
    // done in destructor
}
