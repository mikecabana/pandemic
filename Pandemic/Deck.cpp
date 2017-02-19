#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Deck.h"

Deck::Deck() {}
Deck::~Deck() {}

void Deck::getAttributes(){
	std::cout << "This is a player deck" << std::endl;
}

void Deck::createDeck(std::vector<PlayerCard> cities, std::vector<PlayerCard> events, std::vector<PlayerCard> epidemics) {
	for (size_t i = 0; i < cities.size(); i++) {
		preDeck.push_back(cities.at(i));
	}

	for (size_t i = 0; i < cities.size(); i++) {
		preDeck.push_back(events.at(i));
	}

	srand((unsigned int)time(NULL)); //initialize the random seed

	

	for (size_t i = 0; i < preDeck.size(); i++) {
		//generates a random number between 0 and preDeck size
		int randIndex = rand() % preDeck.size();
		int e = 0;
		if (i % 12 == 11) {
			deck.push_back(epidemics.at(e));
			e++;
		}
		else
			deck.push_back(preDeck.at(randIndex));
	}
}

std::vector<PlayerCard> Deck::getDeck() {
	return deck;
}