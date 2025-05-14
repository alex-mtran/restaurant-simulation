//written by Alexander Tran - atran388
#include "../lib/Menu.hpp"
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

string capsOn(string &str);
bool isNum(const string &);
Facts ingredientFacts;

int main() {
    ingredientFacts = Facts();
    char myChar = 0;
    char adminCharOne = 0;
    char adminCharTwo = 0;
    string  adminIntInput = "";
    bool validInputBoolean = true;
    IngredientStock* ingredientStock = new IngredientStock();
    Customer customer = Customer();
    AdminStatus adminStatus = AdminStatus();
    AdminLogistics adminLogis = AdminLogistics();
    if (adminStatus.getStatus() == 3) { 
        cout << "Al Dente Amore is permanently closed." << endl;
        delete ingredientStock;
        return 0;
    }

    std::string newName;
    Ingredient* newIngredient;
    Date::Date newDate;

    string username = "";
    string password = "";
    cout << "Enter username: ";
    getline(cin, username);
    
    cout << "Enter password: ";
    getline(cin, password);
    
    if (username == "customer" && password == "customerPassword") {
        if (adminStatus.getStatus() == 2) {
            cout << "Sorry, we are closed." << endl;
            delete ingredientStock;
            return 0;
        }
        do {
            cout << endl; //changed 
            cout << customer.getMenu() << endl;
            cin >> myChar;
            cin.ignore(1,'\n');

            if (myChar == '1') { //view food menu
                cout << FOODMENU::printFoodMenu();
            }
            else if(myChar == '2') { //addItem
                cout << FOODMENU::printFoodMenu() << endl;
                string name;
                cout << "Enter the item name: ";
                getline(cin, name);
                name = capsOn(name);
                
                if (name == "CHEESE PIZZA" || name == "PEPPERONI PIZZA" || name == "COMBO PIZZA" || name == "SHRIMP FETTUCCINE ALFREDO" || name == "SPAGHETTI AND MEATBALLS" || name == "CHICKEN PESTO" || name == "HOUSE SALAD" || name == "SOUTHWEST COBB SALAD" || name == "CHICKEN CAESAR SALAD" || name == "COKE" || name == "LEMONADE" || name == "MARGARITA") {
                    if (FOODMENU::checkIngredientsStock(name, ingredientStock) == false) {
                    cout << "Out of stock. Item cannot be added to cart." << endl;
                    }
                    else {
                        FOODMENU::addToCart(name, customer, ingredientStock);
                        cout << name << " has been added to the cart." << endl;
                    }
                }
                else {
                    cout << "Invalid item name." << endl;
                }
            }
            else if (myChar == '3') { //remove item
                string name;
                cout << "Enter the item name: ";
                getline(cin, name);
                name = capsOn(name);

                if (customer.numOfItemInCart(name) == 0) {
                    cout << "You do not have that item in your cart." << endl;
                }
                else {
                    customer.removeItem(name);
                    cout << name << " has been removed." << endl;
                }
            }
            else if (myChar == '4') { //change item quantity
                string name;
                cout << "Enter the item name: ";
                getline(cin, name);
                name = capsOn(name);
                int numItemInCart = customer.numOfItemInCart(name);

                if (numItemInCart == 0) {
                    cout << "You do not have that item in your cart." << endl;
                }
                else {
                    std::string quantityDesiredStr = "";
                    int quantityDesired = 0;
                    cout << "Enter new quantity: ";
                    cin >> quantityDesiredStr;
                    cin.ignore(1, '\n');

                while (!isNum(quantityDesiredStr) || stoi(quantityDesiredStr) < 0) {
                    cout << "Invalid quantity. Enter new quantity: ";
                    cin >> quantityDesiredStr;
                    cin.ignore(1, '\n');
                }
                quantityDesired = stoi(quantityDesiredStr);
                int oldNumInCart = numItemInCart;
                while (quantityDesired != numItemInCart) {
                    if (quantityDesired < numItemInCart) {
                        customer.removeItem(name);
                    }
                    else if (quantityDesired > numItemInCart) {
                        Goods* itemInCart = customer.itemInCart(name);
                        string goodsName = itemInCart->getName();
                        double goodsPrice = itemInCart->getPrice();
                        if(FOODMENU::checkIngredientsStock(goodsName, ingredientStock)) {
                            string capsName = capsOn(goodsName);
                            vector<Ingredient*> ingredients = vector<Ingredient*>();
                            FOODMENU::addIngredients(capsName, ingredients, ingredientStock);
                            Goods* good = new Goods(capsName, goodsPrice, ingredients);
                            customer.addItem(good);
                            cout << name << " added to order.\n";
                        }
                        else {
                            cout << "Another " << name << " cannot be added to the order." << endl;
                            break;
                        }
                    }
                    numItemInCart = customer.numOfItemInCart(name);
                }
                cout << name << " quantity: " << oldNumInCart << " changed to " << customer.numOfItemInCart(name) << '.' << endl;
                }
            }
            else if (myChar == '5') { //print total
                cout << "Total of cart is: $" << customer.calculateTotal() << endl;
            }
            else if (myChar == '6') { //view details (macros)
                string name;
                cout << "Enter item name: ";
                getline(cin, name);
                name = capsOn(name);

                Goods* itemInCart = customer.itemInCart(name);
                if (itemInCart == nullptr) {
                    cout << "Item does not exist." << endl;
                }
                else {
                    customer.viewDescription(itemInCart);
                    cout << endl;
                }
            }
            else if (myChar == '7') { //view cart
                customer.viewCart();
            }
            else if (myChar == 'q') {
                cout << "Order complete." << endl;
            }
            else {
                cout << "That is not a valid option." << endl;
            }
        } while (myChar != 'q');
        //order completed
        double tax = customer.calculateTotal() * 0.08;
        customer.viewCart();
        cout << "------------------------" << endl;
        printf("Sub Total: $%.2f\n", customer.calculateTotal());
        printf("Tax: $%.2f\n", tax);
        printf("Total: $%.2f\n", customer.calculateTotal() + tax);
        cout << "Thank you for ordering at Al Dente Amore! Come back soon!" << endl;
    }
    else if (username == "admin" && password == "adminPassword") {
        do{
            std::cout << "Choose a service:\n(1) Ingredient Stock\n(2) Door Lock\n(1-2): ";
            std::cin >> adminCharOne;
            validInputBoolean = true;

            switch(adminCharOne){
            case '1':
                do{
                std::cout << adminLogis.getMenu();
                std::cin >> adminCharTwo;

                switch(adminCharTwo){

                case '1':
                    std::cout << ingredientStock->str() << std::endl;
                    break;
                case '2':
                    std::cout << "Available ingredients:" << std::endl;
                    for(unsigned i = 0; i < ingredientFacts.numOfIngredients(); i++)
                        std::cout << "(" << i + 1 << ") " << ingredientFacts.getIngredientFacts(static_cast<INGREDIENT>(i)).name << std::endl;
                    std::cout << "(1-" << ingredientFacts.numOfIngredients() << "): ";
                    std::cin >> adminIntInput;
                    while(!isNum(adminIntInput) || stoi(adminIntInput) < 1 || stoi(adminIntInput) > ingredientFacts.numOfIngredients()){
                        std::cout << "Invalid input, try again. (1-" << ingredientFacts.numOfIngredients() << "): ";
                        std::cin >> adminIntInput;
                    }
                    newDate = Date::Date(ingredientFacts.getIngredientFacts(static_cast<INGREDIENT>(stoi(adminIntInput))).expTime);
                    newName = std::string(ingredientFacts.getIngredientFacts(static_cast<INGREDIENT>(stoi(adminIntInput)-1)).name);
                    newIngredient = new Ingredient(newName, newDate);
                    ingredientStock->add(newIngredient);
                    std::cout << "INGREDIENT ADDED:\n\t" << newIngredient->str() << std::endl;
                    break;
                case 'q':
                    std::cout << "Quitting...\n";
                    myChar = 'q';
                    break;
                default :
                    std::cout << "Invalid input, try again.\n";
                    validInputBoolean = false;
                    break;
                }
                } while(!validInputBoolean);
                break;
            case '2':
            do{
                std::cout << adminStatus.getMenu();
                std::cin >> adminCharTwo;

                switch(adminCharTwo){
                case '1':
                    adminStatus.open();
                    std::cout << "Al Dente Amore is now open!" << std::endl;
                    break;
                case '2':
                    adminStatus.close();
                    std::cout << "Al Dente Amore is now closed to customers." << std::endl;
                    break;
                case '3':
                    adminStatus.closePerm();
                    std::cout << "Al Dente Amore is now closed permanently.\n\n\t\t\tG O O D B Y E" << std::endl;
                    delete ingredientStock;
                    return 0;
                    break;
                case 'q':
                    std::cout << "Quitting...\n";
                    myChar = 'q';
                    break;
                default :
                    std::cout << "Invalid input, try again.\n";
                    validInputBoolean = false;
                    break;
                }
                } while(!validInputBoolean);
                break;
            case 'q': 
                myChar = 'q'; 
                break;
            default :
                std::cout << "Invalid input, try again.\n";
            }
        }while(myChar != 'q');
    }
    else {
        cout << "Invalid username or password." << endl;
    }
    cout << "End of program." << endl;
    delete ingredientStock;
    return 0;
}

string FOODMENU::printFoodMenu() {
    string foodMenu = "files/FoodMenu.txt";
    ifstream input(PATH::getPath(foodMenu));
    if (!input.is_open()) {
        return "err";
    }
    string menu = "";
    string line = "";
    while (getline(input, line)) {
        menu.append(line + "\n");
    }
    input.close();
    return menu;
}

void FOODMENU::addToCart(string name, Customer &customer, IngredientStock* ingredientStock) {
    if (name == "CHEESE PIZZA") {
        vector<Ingredient*> ingredients = vector<Ingredient*>();
        FOODMENU::addIngredients(name, ingredients, ingredientStock);
        Goods* good = new Goods("CHEESE PIZZA", 25.99, ingredients);
        customer.addItem(good);
    }
    else if (name == "PEPPERONI PIZZA") {
        vector<Ingredient*> ingredients = vector<Ingredient*>();
        FOODMENU::addIngredients(name, ingredients, ingredientStock);
        Goods* good = new Goods("PEPPERONI PIZZA", 25.99, ingredients);
        customer.addItem(good);
    }
    else if (name == "COMBO PIZZA") {
        vector<Ingredient*> ingredients = vector<Ingredient*>();
        FOODMENU::addIngredients(name, ingredients, ingredientStock);
        Goods* good = new Goods("COMBO PIZZA", 26.99, ingredients);
        customer.addItem(good);
    }
    else if (name == "SHRIMP FETTUCCINE ALFREDO") {
        vector<Ingredient*> ingredients = vector<Ingredient*>();
        FOODMENU::addIngredients(name, ingredients, ingredientStock);
        Goods* good = new Goods("SHRIMP FETTUCCINE ALFREDO", 21.99, ingredients);
        customer.addItem(good);
    }
    else if (name == "SPAGHETTI AND MEATBALLS") {
        vector<Ingredient*> ingredients = vector<Ingredient*>();
        FOODMENU::addIngredients(name, ingredients, ingredientStock);
        Goods* good = new Goods("SPAGHETTI AND MEATBALLS", 19.99, ingredients);
        customer.addItem(good);
    }
    else if (name == "CHICKEN PESTO") {
        vector<Ingredient*> ingredients = vector<Ingredient*>();
        FOODMENU::addIngredients(name, ingredients, ingredientStock);
        Goods* good = new Goods("CHICKEN PESTO", 20.99, ingredients);
        customer.addItem(good);
        }
    else if (name == "HOUSE SALAD") {
        vector<Ingredient*> ingredients = vector<Ingredient*>();
        FOODMENU::addIngredients(name, ingredients, ingredientStock);
        Goods* good = new Goods("HOUSE SALAD", 12.99, ingredients);
        customer.addItem(good);
        }
    else if(name == "SOUTHWEST COBB SALAD") {
        vector<Ingredient*> ingredients = vector<Ingredient*>();
        FOODMENU::addIngredients(name, ingredients, ingredientStock);
        Goods* good = new Goods("SOUTHWEST COBB SALAD", 11.99, ingredients);
        customer.addItem(good);
        }
    else if(name == "CHICKEN CAESAR SALAD") {
        vector<Ingredient*> ingredients = vector<Ingredient*>();
        FOODMENU::addIngredients(name, ingredients, ingredientStock);
        Goods* good = new Goods("CHICKEN CAESAR SALAD", 13.99, ingredients);
        customer.addItem(good);
        }
    else if (name == "COKE") {
        Goods* good = new Goods("COKE", 2.99);
        customer.addItem(good);
    }
    else if (name == "LEMONADE") {
        Goods* good = new Goods("LEMONADE", 2.99);
        customer.addItem(good);
    }
    else if (name == "MARGARITA") {
        Goods* good = new Goods("MARGARITA", 4.99);
        customer.addItem(good);
    }
}

string capsOn(string &str) {
    string copy(str);
    for (unsigned int i = 0; i < str.size(); i++) {
        copy[i] = toupper(str[i]);
    }
    return copy;
}

bool FOODMENU::checkIngredientsStock(string name, IngredientStock* ingredientStock) {
    bool enoughIngredients = true;

    if (name == "CHEESE PIZZA") {
        Ingredient* ingredient  = ingredientStock->getForUse(INGREDIENT::DOUGH);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::MOZZARELLA);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_MARINARA);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
    }
    else if (name == "PEPPERONI PIZZA") {
        Ingredient* ingredient  = ingredientStock->getForUse(INGREDIENT::DOUGH);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::MOZZARELLA);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::PEPPERONI);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_MARINARA);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
    }
    else if (name == "COMBO PIZZA") {
        Ingredient* ingredient  = ingredientStock->getForUse(INGREDIENT::DOUGH);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::MOZZARELLA);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::PEPPERONI);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::GREENS);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::TOMATO);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_MARINARA);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
    }
    else if (name == "SHRIMP FETTUCCINE ALFREDO") {
        Ingredient* ingredient  = ingredientStock->getForUse(INGREDIENT::SHRIMP);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::FETTUCCINE);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_PARMESAN);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
    }
    else if (name == "SPAGHETTI AND MEATBALLS") {
        Ingredient* ingredient  = ingredientStock->getForUse(INGREDIENT::SPAGHETTI);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::MEATBALL);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_MARINARA);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
    }
    else if (name == "CHICKEN PESTO") {
        Ingredient* ingredient  = ingredientStock->getForUse(INGREDIENT::CHICKEN);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::PESTO);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::SPAGHETTI);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
    }
    else if (name == "HOUSE SALAD") {
        Ingredient* ingredient  = ingredientStock->getForUse(INGREDIENT::GREENS);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::TOMATO);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_SECRET);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
    }
    else if(name == "SOUTHWEST COBB SALAD") {
        Ingredient* ingredient  = ingredientStock->getForUse(INGREDIENT::GREENS);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::MOZZARELLA);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::TOMATO);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::SOUTHWESTDRESSING);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
    }
    else if(name == "CHICKEN CAESAR SALAD") {
        Ingredient* ingredient  = ingredientStock->getForUse(INGREDIENT::GREENS);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::MOZZARELLA);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::CHICKEN);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_SECRET);
        if (ingredient == nullptr) {
            enoughIngredients = false;
        }
    }
    return enoughIngredients;
}

void FOODMENU::addIngredients(string name, vector<Ingredient*> &ingredients, IngredientStock* ingredientStock) {
    if (name == "CHEESE PIZZA") {
        Ingredient* ingredient = ingredientStock->getForUse(INGREDIENT::DOUGH);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::MOZZARELLA);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_MARINARA);
        ingredients.push_back(ingredient);
    }
    else if (name == "PEPPERONI PIZZA") {
        Ingredient* ingredient = ingredientStock->getForUse(INGREDIENT::DOUGH);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::MOZZARELLA);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::PEPPERONI);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_MARINARA);
        ingredients.push_back(ingredient);
    }
    else if (name == "COMBO PIZZA") {
        Ingredient* ingredient = ingredientStock->getForUse(INGREDIENT::DOUGH);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::MOZZARELLA);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::PEPPERONI);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::GREENS);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::TOMATO);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_MARINARA);
        ingredients.push_back(ingredient);
    }
    else if (name == "SHRIMP FETTUCCINE ALFREDO") {
        Ingredient* ingredient = ingredientStock->getForUse(INGREDIENT::SHRIMP);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::FETTUCCINE);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_PARMESAN);
        ingredients.push_back(ingredient);
    }
    else if (name == "SPAGHETTI AND MEATBALLS") {
        Ingredient* ingredient = ingredientStock->getForUse(INGREDIENT::SPAGHETTI);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::MEATBALL);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_MARINARA);
        ingredients.push_back(ingredient);
    }
    else if (name == "CHICKEN PESTO") {
        Ingredient* ingredient = ingredientStock->getForUse(INGREDIENT::CHICKEN);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::PESTO);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::SPAGHETTI);
        ingredients.push_back(ingredient);
    }
    else if (name == "HOUSE SALAD") {
        Ingredient* ingredient = ingredientStock->getForUse(INGREDIENT::GREENS);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::TOMATO);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_SECRET);
        ingredients.push_back(ingredient);
    }
    else if (name == "SOUTHWEST COBB SALAD") {
        Ingredient* ingredient = ingredientStock->getForUse(INGREDIENT::GREENS);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::MOZZARELLA);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::TOMATO);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::SOUTHWESTDRESSING);
        ingredients.push_back(ingredient);
    }
    else if (name == "CHICKEN CAESAR SALAD") {
        Ingredient* ingredient = ingredientStock->getForUse(INGREDIENT::GREENS);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::MOZZARELLA);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::CHICKEN);
        ingredients.push_back(ingredient);
        ingredient = ingredientStock->getForUse(INGREDIENT::SAUCE_SECRET);
        ingredients.push_back(ingredient);
    }
    ingredientStock->reserve(ingredients);
}

bool isNum(const std::string &str){
    for(unsigned i = 0; i < str.size(); i++)
        if(!isdigit(str.at(i)))
            return false;
    return true;
}