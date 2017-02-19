#pragma once
#include <iostream>
#include <vector>
#include "PlayerCard.h"

class Deck {
public:
	Deck();
	~Deck();
	void getAttributes();
	void createDeck(std::vector<PlayerCard> cities, std::vector<PlayerCard> events, std::vector<PlayerCard> epidemics);
	std::vector<PlayerCard> getDeck();
private:
	std::vector<PlayerCard> preDeck;
	std::vector<PlayerCard> deck;
};