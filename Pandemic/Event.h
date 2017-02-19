#pragma once
#include <iostream>
#include <string>
#include "PlayerCard.h"

class Event : public PlayerCard {
public:
	Event(std::string name, std::string desc);
	~Event();
	void getAttributes();
private:
	std::string name;
	std::string description;
};