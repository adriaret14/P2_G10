#pragma once
#include "DataManagement.h"
#include "Player.h"
#include <iostream>
class Input
{
public:
	Input(DataManagement &, Player &);
	~Input();

	void addBasics();					//Metodo para a�adir los elementos basicos al inventario del jugador
	void addElement(int);				//Metodo para a�adir un elemento espec�fico al inventario del jugador
	void delElement(int);				//Metodo para borrar un elemento espec�fico del inventario del jugador
	void info(int);						//Metodo de consulta con Wikipedia para recibir informacion de un elemento
	void sort();						//Metodo de ordenado del inventario del jugador
	void clean();						//Metodo para eliminar todos los elementos repetidos del inventario
	void help();						//Metodo para mostrar la lista de comandos disponibles por pantalla

private:
	DataManagement &dm;
	Player &p;
};

