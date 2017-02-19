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
	PlayerCard *city2(new City("tor", "blue", 1000000));
	PlayerCard *city3(new City("lav", "blue", 1000000));
	PlayerCard *city4(new City("que", "blue", 1000000));
	PlayerCard *city5(new City("ota", "blue", 1000000));
	city->getAttributes();
	city2->getAttributes();
	city3->getAttributes();
	city4->getAttributes();
	city5->getAttributes();
	std::cout << std::endl;

	//testing epidemic card class
	PlayerCard *epi(new Epidemic());
	epi->getAttributes();
	std::cout << std::endl;

	//testing event card class
	PlayerCard *eve(new Event("Airlift", "Move any one pawn to any city. Get permission before moving another player's pawn"));
	eve->getAttributes();
	std::cout << std::endl;

	//testing vector with inheritance
	std::vector<PlayerCard> test;
	test.push_back(*city);
	test.push_back(*city2);
	test.push_back(*city3);
	test.push_back(*city4);
	test.push_back(*city5);
	test[0].getAttributes();
	test[1].getAttributes();

	return 0;
}
