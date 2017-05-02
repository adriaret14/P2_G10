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

std::string Player::getStringElement(int num)
{
	return inventario[num];
}

void Player::sort()
{
	bool flag = true;
	int j = 0;
	std::string tmp;
	while (flag)
	{
		flag = false;
		j++;
		for (int i = 0; i < inventario.size() - j; i++)
		{
			if (inventario[i] > inventario[i + 1]) {
				tmp = inventario[i];
				inventario[i] = inventario[i + 1];
				inventario[i + 1] = tmp;
				flag = true;
			}
		}
	}
}

void Player::clean()
{
}




