#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include "City.h"
#include "Event.h"
#include "Epidemic.h"
#include "PlayerCard.h"
#include "Deck.h"
#include "Player.h"


int main() {
	std::srand((int)time(0));

	//vectors to hold card objects
	std::vector<PlayerCard*> cities;
	std::vector<PlayerCard*> events;
	std::vector<PlayerCard*> epidemics;

	//creating city cards
	std::ifstream infile("G:\\My Documents\\Visual Studio 2013\\Projects\\pandemic\\cities.txt");
	std::string name, color;
	int pop;
	while (infile >> name >> color >> pop){
		cities.push_back(new City(name, color, pop));
	}

	for (int i = 0; i < 6; i++){
		epidemics.push_back(new Epidemic());
	}
	
	//creating event cards
	events.push_back(new Event("Airlift", "Move any one pawn to any city. Get permission before moving another player's pawn."));
	events.push_back(new Event("One Quiet Night", "The next player to begin the Playing The Infection phase of their turn may skip that phase entirely."));
	events.push_back(new Event("Forecast", "Examine the top 6 cards of the Infection Draw Pile, rearrange them in the order of your choice, then place them back on the pile."));
	events.push_back(new Event("Government Grant","Add a Research Station to any city for free."));
	events.push_back(new Event("Resilient Population", "Take a card from the Infection Discard Pile and remove it from the game."));
	
	//create a deck
	Deck *deck(new Deck());
	deck->createDeck(cities, events, epidemics);
	//output deck
	/*std::cout << "Deck Size = " << deck->getDeck().size() << std::endl;
	for (int i = 0; i < deck->getDeck().size(); i++){
		deck->getDeck()[i]->getAttributes();
		std::cout << "Card: " << i << std::endl;
		std::cout << std::endl;
	}*/

	//initialize 2 players
	Player *p1(new Player("Tom"));
	Player *p2(new Player("Tim"));


	//populate individual player hands
	for (int i = 0; i < deck->getPlayerHand().size(); i++){
		p1->addCard(deck->getPlayerHand().at(i));
		p2->addCard(deck->getPlayerHand().at(i + 1));
		i = i + 1;
	}

	//display player hands
	std::cout << "Player " << p1->getName() << "'s hand:" << std::endl;
	for (int i = 0; i < p1->getHand().size(); i++){
		p1->getHand()[i]->getAttributes();
		std::cout << std::endl;
	}

	std::cout << std::endl;
	
	std::cout << "Player " << p2->getName() << "'s hand:" << std::endl;
	for (int i = 0; i < p2->getHand().size(); i++){
		p2->getHand()[i]->getAttributes();
		std::cout << std::endl;
	}


	
	return 0;
}
