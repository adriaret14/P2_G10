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

void Player::addBasics()
{
	inventario.push_back("Air");
	inventario.push_back("Earth");
	inventario.push_back("Fire");
	inventario.push_back("Water");
}

void Player::addElement(int num)
{
	inventario.push_back(this->getStringElement(num));
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

std::string Player::getStringElement(int num)
{
	return inventario[num];
}


