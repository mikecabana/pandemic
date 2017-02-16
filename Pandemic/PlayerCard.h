#pragma once
#include <iostream>
#include <string>

class PlayerCard {
public:
	PlayerCard();
	std::string getCardType();
protected:
	std::string cardtype;
};