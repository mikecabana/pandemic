#include <iostream>
#include <string>
#include "City.h"


City::City(std::string name, std::string color, int pop) : PlayerCard("city") {
	cityname = name;
	citycolor = color;
	population = pop;
}

void City::getAttributes() {
	std::cout << "City Name: " << cityname << std::endl;
	std::cout << "Color: " << citycolor << std::endl;
	std::cout << "Population: " << population << std::endl;
}

std::string City::getCityName(){
	return cityname;
}

std::string City::getColor(){
	return citycolor;
}

int City::getPop(){
	return population;
}




