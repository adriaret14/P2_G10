#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#include "DataManagement.h"
#include "Player.h"
#include "Input.h"



void main() {


	//Bucles para recorrer todo el unordered_map

	/*for (auto it = mapa.begin(); it != mapa.end(); it++) {
		std::cout << it->first  << " //// "<< it->second.first << " - " << it->second.second << std::endl;
	}*/

	/*for (auto it = datos.mapa.begin(); it != datos.mapa.end(); it++) {
		std::cout << it->first << " //// " << it->second.first << " - " << it->second.second << std::endl;
	}*/


	//Creamos los objetos necesarios

	DataManagement datos("elements.dat");
	Player jugador;
	Input entrada(datos, jugador);

	//Pruebas metodos jugador

	//jugador.addElement(1);
	//jugador.addBasics();
	//jugador.delElement(3);
	//std::vector<std::string> aux = jugador.getInv();
	//std::cout << aux[4];
	//std::cout << jugador.getStringElement(2);

	
	//Pruebas de Input
	//entrada.info(1);
	//entrada.help();
	//std::cout << jugador.getStringElement(6);

	std::cout << "-------------------------------------" << std::endl;
	std::cout << " ****** BLEINZ & KANG ALCHEMY ****** " << std::endl;
	std::cout << "-------------------------------------" << std::endl << std::endl << std::endl;

	std::cout << "-Enter 2 numbers of your element list to combine them" << std::endl;
	std::cout << "-Enter 'add' and the number of an element to make a copy" << std::endl;
	std::cout << "-Enter 'add basics' to add a copy of the 4 basics elements [Air, Earth, Fire, Water]" << std::endl;
	std::cout << "-Enter 'delete' and the number of an element to erase it from your element list" << std::endl;
	std::cout << "-Enter 'info' and the number of an element to get information on Wikipedia" << std::endl;
	std::cout << "-Enter 'sort' to sort by alphabetical your elements list" << std::endl;
	std::cout << "-Enter 'clean' to erase all the repeated elements from your elements list" << std::endl;
	std::cout << "-Enter 'help' to show this tutorial again" << std::endl << std::endl << std::endl;
	std::cout << "GOOD LUCK ALCHEMIST!" << std::endl << std::endl;

	int flag = 0;
	do {
		//´Para parar el juego debemos pulsar escape
		if (_kbhit()) {
			if (_getch()==27) {
				flag = 1;
			}
		}

		
		std::string palabra;
		std::cin >> palabra;

		switch (palabra)//		-_-  malditas enums tt
		{

		}





	} while (flag!=1);
}