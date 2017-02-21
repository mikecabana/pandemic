#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "PlayerCard.h"

class Player{
public:
	Player(std::string name);
	~Player();
	void addCard(PlayerCard *card);
	std::vector<PlayerCard*> getHand();
	std::string getName();
private:
	std::string name;
	std::vector<PlayerCard*> hand;
};