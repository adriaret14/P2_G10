#pragma once
#include "DataManagement.h"
#include "Player.h"
#include <iostream>
#include <windows.h>
#include <string>

class Input
{
public:
	Input(DataManagement &, Player &);				//Constructor de la clase Input
	~Input();										//Destructor de la clase Input

	
	void info(int);									//Metodo de consulta con Wikipedia para recibir informacion de un elemento
	void sort();									//Metodo de ordenado del inventario del jugador
	void clean();									//Metodo para eliminar todos los elementos repetidos del inventario
	void help();									//Metodo para mostrar la lista de comandos disponibles por pantalla

private:

	DataManagement &dm;								//Objeto de tipo DataManagement pasado por referencia
	Player &p;										//Onjeto de tipo Player pasado por referencia
};

