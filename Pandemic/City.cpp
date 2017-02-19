#include <iostream>
#include <string>
#include "City.h"

City::City(std::string name, std::string color, int pop) {
	cityname = name;
	citycolor = color;
	population = pop;
}

City::~City(){}

void City::getAttributes() {
	std::cout << "City Name: " << cityname << std::endl;
	std::cout << "Color: " << citycolor << std::endl;
	std::cout << "Population: " << population << std::endl;
}



