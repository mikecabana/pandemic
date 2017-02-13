#include <iostream>
#include <string>
#include "City.h"
#include "Epidemic.h"

int main() {
	PlayerCard *Montreal = new City("Montreal", "blue", 1000000);
	Montreal->getAttributes();

	//std::cout << Montreal->getCardType() << std::endl;
	//Montreal.getCityName();
	//Montreal.getColor();
	//Montreal.getPop();
	//Montreal.getCardType();

	PlayerCard *e1 = new Epidemic();
	e1->display();

	return 0;
}
