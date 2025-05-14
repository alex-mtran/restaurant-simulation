// written by Scott Gonzalez Barrios - sgonz266
#include "../lib/User.hpp"

User::User(){}

User::User(std::string username, std::string password, std::string menuFile){
    this->username = username;
    this->password = password;
    this->menuFile = menuFile;
    this->ingredientFile = "../files/IngredientFile.txt";
}

std::string User::initMenu(std::string file){
    std::ifstream input(PATH::getPath(file));
        if(!input.is_open())
        return "err";
    std::string menu = "";
    std::string line = "";
    while(getline(input, line))
        menu.append(line + "\n");
    input.close();
    return menu; // finish
}

bool User::verifyUsername(std::string username){
    return this->username == username;
}

bool User::verifyPassword(std::string password){
    return this->password == password;
}

User::~User(){
    // save file stuff
}