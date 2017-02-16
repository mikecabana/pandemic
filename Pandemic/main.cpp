#include <iostream>
#include <string>
#include "City.h"
#include "Epidemic.h"
#include "Roles.h"
#include "PlayerCard.h"

int main() {
	//testing city card class
	City Montreal = City("Montreal", "blue", 1000000);
	Montreal.getAttributes();
	std::cout << Montreal.getCardType() << std::endl;

	//testing epidemic card class
	Epidemic ep1 = Epidemic();
	ep1.display();
	std::cout << ep1.getCardType() << std::endl;

	//testing role card class
	Roles p1 = Roles("p1", 10);
	p1.output();

	//std::cout << Montreal->getCardType() << std::endl;
	//Montreal.getCityName();
	//Montreal.getColor();
	//Montreal.getPop();
	//Montreal.getCardType();

	//PlayerCard *e1 = new Epidemic();
	//e1->display();

	return 0;
}
