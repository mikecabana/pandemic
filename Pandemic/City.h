#pragma once
#include <iostream>
#include <string>
#include "PlayerCard.h"

class City{
public:
	City(std::string name, std::string color, int pop);
	void getAttributes();
	std::string getCityName();
	std::string getColor();
	int getPop();
private:
	std::string cityname;
	std::string citycolor;
	int population;
};