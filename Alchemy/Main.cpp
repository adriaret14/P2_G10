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

enum class PALABRA {
	ADD,
	DEL,
	INFO,
	SORT,
	CLEAN,
	HELP,
	MAX
};

void main() {


	//Bucles para recorrer todo el unordered_map

	/*for (auto it = mapa.begin(); it != mapa.end(); it++) {
		std::cout << it->first  << " //// "<< it->second.first << " - " << it->second.second << std::endl;
	}*/

	/*for (auto it = datos.mapa.begin(); it != datos.mapa.end(); it++) {
		std::cout << it->first << " //// " << it->second.first << " - " << it->second.second << std::endl;
	}*/
	std::unordered_map<std::string, PALABRA>palabras;
	palabras["add"] = PALABRA::ADD;
	palabras["delete"] = PALABRA::DEL;
	palabras["info"] = PALABRA::INFO;
	palabras["clean"] = PALABRA::CLEAN;
	palabras["help"] = PALABRA::HELP;
	palabras["sort"] = PALABRA::SORT;

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

		std::cout << "Your current score: " << jugador.getScore() << std::endl;
		std::cout << "You have these elements: " << std::endl;

		//Pol para recorrer vctores, dado que nos permiten acceder por posicion ahorrate los iteradores, es mas eficaz usar un contador.
		for (int i=0; i < jugador.getInventorySize(); i++) { 
			std::cout << i+1 << ": " << jugador.getStringElement(i) << std::endl;	
		}
		std::string command;
		std::string parameter;
		std::string input;
		bool param;
		bool numbers;
		do {
			std::cout << std::endl << "What do you want to do?" << std::endl;
			std::getline(std::cin, input);
			std::size_t pos = input.find(" ");
			
			
			if (pos != std::string::npos) {
				command = input.substr(0, pos);
				parameter = input.substr(pos + 1);
				param = true;
			}
			else {
				command = input;
				param = false;
			}

			
			
			if (palabras.count(command) == 0) { std::cout << "Command unrecognized. Please type help to see the list of commands." << std::endl; }
		} while (palabras.count(command) == 0);
			
		
		switch (palabras[command])
		{
			case PALABRA::ADD:
				if (parameter == "basics") {
					jugador.addBasics();
				}
				else {
					jugador.addElement(std::stoi(parameter)-1);
				}
				break;
			case PALABRA::DEL:
				jugador.delElement(std::stoi(parameter) - 1);
				break;
			case PALABRA::INFO:
				entrada.info(std::stoi(parameter)-1);
				break;
			case PALABRA::SORT:
				jugador.sort();
				break;
			case PALABRA::CLEAN:
				jugador.clean();
				break;
			case PALABRA::HELP:
				entrada.help();
				break;					
		}
	} while (flag!=1);
}