#include <iostream>
#include <string>
#include "Epidemic.h"

Epidemic::Epidemic(){
	cardtype = "epidemic";
}

void Epidemic::display()
{
	std::cout << "Epidemic!" << std::endl;
	std::cout << "1 - " << std::endl;
	std::cout << "2 - " << std::endl;
	std::cout << "3 - " << std::endl;
}
