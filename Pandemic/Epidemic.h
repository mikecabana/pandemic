#pragma once
#include <iostream>
#include <string>
#include "PlayerCard.h"

class Epidemic:public PlayerCard{
public:
	Epidemic();
	void display();
private:
	std::string description;
};