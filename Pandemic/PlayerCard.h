#pragma once
#include <iostream>
#include <string>

class PlayerCard {
public:
	PlayerCard(std::string type);
	std::string getCardType();
private:
	std::string cardtype;
};