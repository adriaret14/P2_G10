#pragma once
#include <vector>
#include <string>
class Player
{
public:
			
	Player();										//Constructor de la clase Player
	~Player();										//Destructor de la clase Player

	void setScore(int);								//Metodo para modificar la puntuacion del jugador
	int getScore();									//Metodo para consultar la puntuacion del jugador
	void addBasics();								//Metodo para añadir los 4 elementos basicos al inventario del jugador
	void addElement(int);							//Metodo para añadir un elemento al inventario del jugador
	void delElement(int);							//Metodo para eliminar un elemento de del inventario del jugador
	std::vector<std::string> getInv();				//Metodo para consultar el inventario del jugador
	void updateDesc(std::string);					//Metodo para modificar la lista de elementos descubiertos del jugador
	std::vector<std::string> getDesc();				//Metodo para consultar la lista de elementos descubiertos
	std::string getStringElement(int);				//Metodo para consultar el nombre de un elemento dado su numero

private:

	int score;										//Puntuación del jugador
	std::vector<std::string>inventario;				//Inventario del juagdor
	std::vector<std::string>descubiertos;			//Lista de elementos descubiertos del jugador

};

