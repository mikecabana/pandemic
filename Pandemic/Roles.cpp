#include <iostream>
#include <string>
#include "Roles.h"

Roles::Roles(std::string n, int i){
    name = n;
    id = i;
}

void Roles::output(){
    std::cout << name << std::endl << id << std::endl;
}
