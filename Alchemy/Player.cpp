#include "Player.h"



Player::Player() :
	score(0),
	inventario({"Air", "Earth", "Fire", "Water"})
{
}


Player::~Player()
{
}

void Player::setScore(int n)
{
	score = n;
}

int Player::getScore()
{
	return score;
}

void Player::addElement(std::string element)
{
	inventario.push_back(element);
}

void Player::delElement(int i)
{
	inventario.erase(inventario.begin() + i);
}

std::vector<std::string> Player::getInv()
{
	return inventario;
}

void Player::updateDesc(std::string elemento)
{
	descubiertos.push_back(elemento);
}

std::vector<std::string> Player::getDesc()
{
	return descubiertos;
}


