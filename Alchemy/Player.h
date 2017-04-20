#pragma once
#include <vector>
#include <string>
class Player
{
public:

	Player();
	~Player();

	void setScore( int );
	int getScore();

	void updateInv(std::string, std::string);
	std::vector<std::string> getInv();

	void updateDesc(std::string);
	std::vector<std::string> getDesc();

private:

	int score;
	std::vector<std::string>inventario;
	std::vector<std::string>descubiertos;

};

