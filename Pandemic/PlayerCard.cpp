#include "PlayerCard.h"
#include <iostream>
#include <string>


PlayerCard::PlayerCard(std::string type)
{
	cardtype = type;
}

std::string PlayerCard::getCardType()
{
	return cardtype;
}
