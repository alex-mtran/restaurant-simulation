// written by Scott Gonzalez Barrios - sgonz266
#include "../lib/AdminStatus.hpp"


AdminStatus::AdminStatus() : User("admin", "adminPassword", "files/AdminStatusMenu.txt"){
    this->menu = this->initMenu(this->menuFile);
    this->statusFile = "files/StatusFile.csv";
    this->status = this->statusInit();
}

AdminStatus::~AdminStatus(){
}

int AdminStatus::statusInit(){
    std::ifstream input(PATH::getPath(this->statusFile));
    if(!input.is_open())
        return 0; // err
    int val = 0;
    input >> val;
    input.close();
    return val;
}

int AdminStatus::getStatus(){
    return this->status;
}

void AdminStatus::setStatus(int number){
    std::ofstream output(PATH::getPath(this->statusFile), std::ofstream::trunc);
    if(output.is_open()){
        output << number;
        output.close();
        this->status = this->statusInit(); // reset variable
    }
    else
        std::cout << "err" << std::endl;
    output.close();
}

void AdminStatus::open(){ this->setStatus(1); }
void AdminStatus::close(){ this->setStatus(2); }
void AdminStatus::closePerm(){ this->setStatus(3); }

std::string AdminStatus::getMenu(){
    return "Admin's menu:\n" + this->menu;
}