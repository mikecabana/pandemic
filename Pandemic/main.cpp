#include <iostream>
#include <string>
#include <vector>
#include "City.h"
#include "Event.h"
#include "Epidemic.h"
#include "PlayerCard.h"

int main() {
	//testing city card class
	PlayerCard *city(new City("mtl", "blue", 1000000));
	city->getAttributes();
	std::cout << std::endl;

	//testing epidemic card class
	PlayerCard *epi(new Epidemic());
	epi->getAttributes();
	std::cout << std::endl;

	//testing event card class
	PlayerCard *eve(new Event("Airlift", "Move any one pawn to any city. Get permission before moving another player's pawn"));
	eve->getAttributes();
	std::cout << std::endl;

	std::vector<PlayerCard> test;
	test.push_back(*city);
	test.data()->getAttributes();

	std::vector<PlayerCard>::iterator it;

	for (it = test.begin(); it != test.end(); ++it) {
		std::cout << "t" << std::endl;
		it->getAttributes();
	}


	return 0;
}
