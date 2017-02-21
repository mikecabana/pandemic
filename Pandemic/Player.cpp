#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

Player::Player(std::string n){
	name = n;
};

Player::~Player(){};

void Player::addCard(PlayerCard *card){
	hand.push_back(card);
}

std::vector<PlayerCard*> Player::getHand(){
	return hand;
}

std::string Player::getName(){
	return name;
}