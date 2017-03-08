#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include "City.h"
#include "Event.h"
#include "Epidemic.h"
#include "Deck.h"
#include "Player.h"
#include "reference_cards.h"


int main() {
	std::srand((int)time(0));

	//vectors to hold card objects
	std::vector<PlayerCard*> cities;
	std::vector<PlayerCard*> events;
	std::vector<PlayerCard*> epidemics;

	//creating city cards
	std::ifstream infile("..\\cities.txt");
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
	//deck->displayDeck();


	std::cout << "Welcome to Pandemic assignment 1 part 3 driver." << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "What is the name of player 1: ";
	std::string player1;
	std::cin >> player1;
	std::cout << "What is the name of player 2: ";
	std::string player2;
	std::cin >> player2;

	//initialize 2 players
	Player *p1(new Player(player1));
	Player *p2(new Player(player2));

	p1->getReferenceCard();
	//populate individual player hands
	for (int i = 0; i < deck->getPlayerHand().size(); i++){
		p1->addCard(deck->getPlayerHand().at(i));
		p2->addCard(deck->getPlayerHand().at(i + 1));
		i = i + 1;
	}

	//decisions decisions - hard coded atm. will be possibly implemetned as a functon of class game.
	bool p1HasEvent = false;
	bool p2HasEvent = false;
	int o;
	std::string option;
	start: {

		std::cout << p1->getName() << "'s turn." << std::endl;
		std::cout << "These are your cards." << std::endl;
		std::cout << std::endl;
		p1->displayHand();
		std::cout << std::endl;
		o = 1;
		std::cout << "Below are your options. Enter an option number to make a decision." << std::endl;
		std::cout << o << " : do nothing because city card are useless in this version." << std::endl;
		for (int i = 0; i < p1->getHand().size(); i++) {
			if (p1->getHand()[i]->getType() != "city") {
				p1HasEvent = true;
			}
		}

		if (p1HasEvent == true) {
			o = 2;
			std::cout << o << " : use 1 event card." << std::endl;
		}
		std::cout << o + 1 << " : end the game." << std::endl;
		std::cin >> option;

		options: {
			if (option == "1") {
				std::cout << "Next players turn" << std::endl;
				goto proceed;
			}
			else if (option == "2" && p1HasEvent == true) {
				std::cout << "Turns out events are useless too. Next players turn.";
				goto proceed;
			}
			else if (option == std::to_string(o + 1)) {
				std::cout << "Game ended!" << std::endl;
				goto endgame;
			}
			else {
				std::cout << "Wrong input. Try again!" << std::endl;
				goto options;
			}
		}
		 proceed:

		//next players turn
		std::cout << p2->getName() << "'s turn." << std::endl;
		std::cout << "These are your cards." << std::endl;
		std::cout << std::endl;
		p2->displayHand();
		o = 1;
		std::cout << std::endl;
		std::cout << "Below are your options. Enter an option number to make a decision." << std::endl;
		std::cout << o << " : do nothing because city card are useless in this version." << std::endl;
		for (int i = 0; i < p2->getHand().size(); i++) {
			if (p2->getHand()[i]->getType() != "city") {
				p2HasEvent = true;
			}
		}

		if (p2HasEvent == true) {
			o = 2;
			std::cout << o << " : use 1 event card." << std::endl;
		}
		std::cout << o + 1 << " : end the game." << std::endl;
		std::cin >> option;

		options2: {
			if (option == "1") {
				std::cout << "Next players turn." << std::endl;
				goto proceed2;
			}
			else if (option == "2" && p2HasEvent == true) {
				std::cout << "Turns out events are useless too. Next players turn." << std::endl;
				goto proceed2;
			}
			else if (option == std::to_string(o + 1)) {
				std::cout << "Game ended!" << std::endl;
				goto endgame;
			}
			else {
				std::cout << "Wrong input. Try again!" << std::endl;
				goto options2;
			}
		}
			  proceed2:
				  goto start;
	}
	endgame:

	//delete all pointers
	for (auto it = cities.begin(); it != cities.end(); it++)
		delete *it;
	cities.clear();

	for (auto it = events.begin(); it != events.end(); it++)
		delete *it;
	events.clear();

	for (auto it = epidemics.begin(); it != epidemics.end(); it++)
		delete *it;
	epidemics.clear();

	delete deck, p1, p2;
	deck, p1, p2 = NULL;
	
	return 0;
}
