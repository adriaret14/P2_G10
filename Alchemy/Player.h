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
	void addBasics();								//Metodo para a�adir los 4 elementos basicos al inventario del jugador
	void addElement(int);							//Metodo para a�adir un elemento al inventario del jugador
	void delElement(int);							//Metodo para eliminar un elemento de del inventario del jugador
	std::vector<std::string> getInv();				//Metodo para consultar el inventario del jugador
	int getInventorySize();							//Metodo para consultar el tama�o de mi inventario
	void pushToDesc(std::string);					//Metodo para modificar la lista de elementos descubiertos del jugador
	std::vector<std::string> getDesc();				//Metodo para consultar la lista de elementos descubiertos
	std::string getStringElement(int);				//Metodo para consultar el nombre de un elemento dado su numero
	void sort();									//Metodo de ordenado del inventario del jugador
	void clean();									//Metodo para eliminar todos los elementos repetidos del inventario
	void pushToInv(std::string);					//Metodo para a�adir un nuevo elemento al inventario
	bool notInDesc(std::string);					//metodo para comprobar si un elemento esta en descubiertos

private:

	int score;										//Puntuaci�n del jugador
	std::vector<std::string>inventario;				//Inventario del juagdor
	std::vector<std::string>descubiertos;			//Lista de elementos descubiertos del jugador

};

