#include "iostream"
#include "gtest/gtest.h"
#include "../lib/Date.hpp"

TEST(DateTests, CurrentDateTest){
    Date::Date date = Date::Date(); // should return current date
    std::cout << "Now: " << date.str() << std::endl; 
}

TEST(DateTests, FutureDateTest){
    Date::Date date = Date::Date(8); // should create 8 days from now
    std::cout << "Now + 8 days: " << date.str() << std::endl;
    date = Date::Date(30); // should create in april (from march 2)
    std::cout << "Now + 30 days: " << date.str() << std::endl;
    date = Date::Date(60); // should create in may (from march 2)
    std::cout << "Now + 60 days: " << date.str() << std::endl;
    date = Date::Date(305); // should create in 2024 (from march 2, 2023)
    std::cout << "Now + 305 days: " << date.str() << std::endl;
}

TEST(DateTests, ValidDateTest){
    Date::Date date = Date::Date(0,9,2021);
    EXPECT_FALSE(date.is_valid());
    date = Date::Date(8,0,2023);
    EXPECT_TRUE(date.is_valid());
    date = Date::Date(8,3,0);
    EXPECT_TRUE(date.is_valid());
}

TEST(DateTests, StringDateTest){
    Date::Date date = Date::Date(8,9,2021);
    EXPECT_EQ(date.str(), "08/09/2021");
    date = Date::Date(8,9,2023);
    EXPECT_FALSE(date.str() == "08/09/2022");
}

TEST(DateTests, InequalityDateTest){
    Date::Date date = Date::Date(8,9,2021);
    Date::Date dateTwo = Date::Date(8,9,2022);
    EXPECT_TRUE(date <= dateTwo);
    date = Date::Date(8,9,2023);
    EXPECT_FALSE(date <= dateTwo);
}