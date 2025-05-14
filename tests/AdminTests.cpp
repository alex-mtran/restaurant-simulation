// written by Scott Gonzalez Barrios - sgonz266
#include "gtest/gtest.h"
#include "../lib/AdminStatus.hpp"
#include "../lib/AdminLogistics.hpp"
#include "../lib/Facts.hpp"
#include <iostream>

TEST(AdminGeneralTests, ConstructTest){
    AdminStatus admin = AdminStatus();

    EXPECT_TRUE(admin.verifyUsername("admin"));
    EXPECT_FALSE(admin.verifyUsername("adminUser"));
    EXPECT_TRUE(admin.verifyPassword("adminPassword"));
    EXPECT_FALSE(admin.verifyPassword("adminPass"));
}


TEST(AdminFileTests, StatusManipTest){
    AdminStatus admin = AdminStatus();
    int original = admin.getStatus();
    int status = original == 1 ? 2 : original == 2 ? 3 : 1; // generate new status
    EXPECT_FALSE(admin.getStatus() == status); // shouldn't generate same statsu
    admin.close(); // sets to 2
    ASSERT_EQ(admin.getStatus(), 2);
    admin.open();  // sets to 1
    ASSERT_EQ(admin.getStatus(), 1);
    admin.closePerm(); // sets to 3
    ASSERT_EQ(admin.getStatus(), 3);
    original == 1 ? admin.open() : original == 2 ? admin.close() : admin.closePerm(); // reset status to original
}

TEST(AdminFactsTest, testFactsInit){
    Facts ingredientFacts = Facts();
    AdminLogistics logistics = AdminLogistics();
    std::cout << ingredientFacts.getIngredientFacts(INGREDIENT::PARMESAN).name << std::endl;
    ASSERT_EQ(ingredientFacts.getIngredientFacts(INGREDIENT::PARMESAN).name, "PARMESAN");
    std::cout << ingredientFacts.getIngredientFacts(INGREDIENT::PEPPERONI).name << std::endl;
    ASSERT_EQ(ingredientFacts.getIngredientFacts(INGREDIENT::PEPPERONI).name, "PEPPERONI");
    std::cout << ingredientFacts.getIngredientFacts(INGREDIENT::SAUCE_ALFREDO).name << std::endl;
    ASSERT_EQ(ingredientFacts.getIngredientFacts(INGREDIENT::SAUCE_ALFREDO).name, "SAUCE_ALFREDO");
    std::cout << ingredientFacts.getIngredientFacts(INGREDIENT::SPAGHETTI).name << std::endl;
    ASSERT_EQ(ingredientFacts.getIngredientFacts(INGREDIENT::SPAGHETTI).name, "SPAGHETTI");
}