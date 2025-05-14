//written by augustine ayoub
// written by Scott Gonzalez Barrios - sgonz266
//written by Alexander Tran - atran388

#ifndef __CUSTOMER_HPP__
#define __CUSTOMER_HPP__
#include "User.hpp"
#include "Goods.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Customer : public User {
    private:
        std::vector<Goods*> myCart;
        double total;
    public:    
        Customer();
        ~Customer();
        // Adds a good to the car
        void addItem(Goods* g);
        // Removes a good from the cart
        void removeItem(string itemToDelete);
        // Returns the number of an item with specified name in the cart
        int numOfItemInCart(string name) const;
        // Returns the Goods* of the item with the specified name in the cart
        Goods* itemInCart(string name) const;
        // View cart
        void viewCart() const;
        // Prints the macros of the items
        void viewDescription(Goods* g) const;
        double calculateTotal();
        virtual string getMenu() override;
        int numInCart() const;
};

#endif
