#include "gtest/gtest.h"
#include "../lib/Customer.hpp"
#include "../lib/Goods.cpp"
#include <iostream>
//written by annabelle le-ale168

TEST(CustomerTests, calculateTotalOneItemInCart){
    Customer customer = Customer();
    Goods* g = new Goods("CHEESE PIZZA",25.99);
    customer.addItem(g);

    EXPECT_EQ(customer.calculateTotal()== 25.99);
    delete g;
}
TEST(CustomerTests, calculateTotalTwoPizzaInCart){
    Customer customer = customer();
    Goods* g = new Goods("CHEESE PIZZA", 25.99);
    customer.addItem(g);
    Goods* g1 = new Goods("COMBO PIZZA", 26.99);
    customer.addItem(g1);

    EXPECT_EQ(customer.calculateTotal() == 52.98);
    delete g;
    delete g1;

}
TEST(CustomerTests, calculateTotalPizzaPastaInCart){
    Customer customer = customer();
    Goods* g = new Goods("CHEESE PIZZA", 25.99);
    customer.addItem(g);
    Goods* g1 = new Goods("CHICKEN PESTO", 20.99);
    customer.addItem(g1);

    EXPECT_EQ(customer.calculateTotal() == 46.98);
    delete g;
    delete g1;
}
TEST(CustomerTests, calculateTotalTwoPastaInCart){
    Customer customer = customer();
    Goods* g = new Goods("SHRIMP FETTUCINE ALFREDO", 21.99);
    customer.addItem(g);
    Goods* g1 = new Goods("CHICKEN PESTO", 20.99);
    customer.addItem(g1);

    EXPECT_EQ(customer.calculateTotal() == 42.98);
    delete g;
    delete g1;
}
TEST(CustomerTests, calculateTotalPastaSaladInCart){
    Customer customer = customer();
    Goods* g = new Goods("SHRIMP FETTUCINE ALFREDO", 21.99);
    customer.addItem(g);
    Goods* g1 = new Goods("HOUSE SALAD", 12.99);
    customer.addItem(g1);

    EXPECT_EQ(customer.calculateTotal() == 34.98);
    delete g;
    delete g1;
}
TEST(CustomerTests, calculateTotalTwoPastaDrinkInCart){
    Customer customer = customer();
    Goods* g = new Goods("SHRIMP FETTUCCINE ALFREDO", 21.99);
    customer.addItem(g);
    Goods* g1 = new Goods("CHICKEN PESTO", 20.99);
    customer.addItem(g1);
    Goods* g2 = new Goods("LEMONADE", 2.99);
    customer.addItem(g2)

    EXPECT_EQ(customer.calculateTotal() == 45.97);
    delete g;
    delete g1;
    delete g2;
}

TEST(CustomerTests, printTotalOneItemInCart){
    Customer customer = Customer();
    Goods* g= new Goods("CHEESE PIZZA", 25.99);
    EXPECT_EQ(customer.printTotal(), "$25.99\n");
    delete g;
}
TEST(CustomerTests, printTotalTwoItemInCart){
    Customer customer = Customer();
    Goods* g= new Goods("CHEESE PIZZA", 25.99);
    Goods* g1= new Goods("CHICKEN PESTO", 20.99);
    EXPECT_EQ(customer.printTotal(), "$46.98\n");
    delete g;
    delete g1;
}
TEST(CustomerTests, printTotalThreeItemInCart){
    Customer customer = Customer();
    Goods* g= new Goods("CHEESE PIZZA", 25.99);
    Goods* g1= new Goods("CHICKEN PESTO", 20.99);
    Goods* g2= new Goods ("COKE", 2.99);
    EXPECT_EQ(customer.printTotal(), "$49.97\n");
    delete g;
    delete g1;
    delete g2;
}
TEST(CustomerTests, printTotalFourItemInCart){
    Customer customer = Customer();
    Goods* g= new Goods("CHEESE PIZZA", 25.99);
    Goods* g1= new Goods("CHICKEN PESTO", 20.99);
    Goods* g2= new Goods ("COKE", 2.99);
    Goods* g3= new Goods("LEMONADE", 2.99);
    EXPECT_EQ(customer.printTotal(), "$52.96\n");
    delete g;
    delete g1;
    delete g2;
    delete g3;
}