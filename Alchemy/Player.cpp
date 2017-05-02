#include "Player.h"
#include <algorithm>



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

int Player::getInventorySize()
{	
	return inventario.size();
}

void Player::updateDesc(std::string elemento)
{
	descubiertos.push_back(elemento);
}

std::vector<std::string> Player::getDesc()
{
	return descubiertos;
}

void Player::pushToInv(std::string element)
{
	inventario.push_back(element);
}

bool Player::notInDesc(std::string str)
{
	for (std::vector<std::string>::iterator it = descubiertos.begin(); it != descubiertos.end(); ++it)
	{
		if (*it == str) {
			return false;
		}
	}
	return true;
}

std::string Player::getStringElement(int num)
{
	return inventario[num];
}

void Player::sort()
{
	std::sort( inventario.begin(), inventario.end());
}

void Player::clean()
{
	sort();
	inventario.erase( std::unique( inventario.begin(), inventario.end() ), inventario.end() );
}




