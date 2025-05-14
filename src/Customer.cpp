// written by Scott Gonzalez Barrios - sgonz266
//written by augustine ayoub
//written by Alexander Tran - atran388
//written by Annabelle Le-ale168

#include "../lib/Customer.hpp"

void Customer::addItem(Goods* g) {
    myCart.push_back(g);
}

void Customer::removeItem(string itemToDelete) {
    if (myCart.size() == 0) {
        cout << "Nothing removed." << endl;
    }

    for (unsigned int i = 0; i < myCart.size(); ++i) {
        if (myCart.at(i)->getName() == itemToDelete) {
            myCart.at(i)->unreserve();
            myCart.erase(myCart.begin() + i);
        }
    }
}

string Customer::getMenu() {
    return "Welcome to Al Dente Amore!\n" + this->menu;
}

Customer::Customer() : User("customer", "customerPassword", "files/CustomerMenu.txt"){
    this->menu = this->initMenu(this->menuFile);
}

int Customer::numOfItemInCart(string name) const {
    int count = 0;

    for (unsigned int i = 0; i < myCart.size(); i++) {
        if (myCart.at(i)->getName() == name) {
            count++;
        }
    }

    return count;
}

int Customer::numInCart() const {
    int count = 0;
    
    for (unsigned int i = 0; i < myCart.size(); i++) {
        count++;
    }

    return count;
}

void Customer::viewCart() const {
    for (unsigned int i = 0; i < myCart.size(); i++) {
        string name = myCart.at(i)->getName();
        double price = myCart.at(i)->getPrice();

        cout << "1 " << name << "   $" << price << endl;
    }
}

Goods* Customer::itemInCart(string name) const{
    for (unsigned int i = 0; i < myCart.size(); i++) {
        if (myCart.at(i)->getName() == name) {
            return myCart.at(i);
        }
    }
    return nullptr;
}

void Customer::viewDescription(Goods* g) const {
    if (g->getName() == "CHEESE PIZZA") {
        cout <<"Ingredients: \n";
        g->Ingredients();
        cout << "Calories: 800, Protein: 80g \n";
    }
    else if (g->getName()== "PEPPERONI PIZZA") {
        cout << "Ingredients: \n";
        g->Ingredients();
        cout << "Calories: 1000, Protein: 100g \n";
    }
    else if (g->getName() == "COMBO PIZZA"){
        cout << "Ingredients: \n";
        g->Ingredients();
        cout << "Calories: 1200, Protein: 120g \n";
    }
    else if (g->getName() =="HOUSE SALAD"){
        cout << "Ingredients: \n";
        g->Ingredients();
        cout << "Calories: 300, Protein: 15g \n";
    }
    else if (g->getName() == "CHICKEN CAESAR SALAD") {
        cout << "Ingredients: \n";
        g->Ingredients();
        cout << "Calories: 400, Protein: 20g \n";
    }
    else if (g->getName() == "SOUTHWEST COBB SALAD"){
        cout << "Ingredients: \n";
        g->Ingredients();
        cout << "Calories: 500, Protein: 20g \n";
    }
    else if (g->getName() == "SHRIMP FETTUCCINE ALFREDO"){
        cout << "Ingredients: \n";
        g->Ingredients();
        cout << "Calories: 600, Protein: 25g \n";
    }
    else if (g->getName() == "CHICKEN PESTO"){
        cout << "Ingredients: \n";
        g->Ingredients();
        cout << "Calories: 550, Protein: 15g \n";
    }
    else if (g->getName() == "SPAGHETTI AND MEATBALLS"){
        cout << "Ingredients: \n";
        g->Ingredients();
        cout << "Calories: 500, Protein: 15g \n";
    }
    else if (g->getName() == "COKE") {
        cout << "Calories: 300 \n";
    }
    else if (g->getName() == "MARGARITA") {
        cout << "Calories: 500 \n";
    }
    else if (g->getName() == "LEMONADE") {
        cout << "Calories: 350 \n";
    }
}

double Customer::calculateTotal() {
    double sum = 0;
    
    for (unsigned int i=0; i < myCart.size(); i++){
    sum += myCart.at(i)->getPrice();
    }
    return sum;  
  }

Customer::~Customer(){
    for(Goods* good : this->myCart)
        delete good;
}