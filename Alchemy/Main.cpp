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

//Enum con el que controlaremos la entrada de órdenes por teclado
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

	//Creamos los objetos y variables necesarios
	std::unordered_map<std::string, PALABRA>palabras;
	palabras["add"] = PALABRA::ADD;
	palabras["delete"] = PALABRA::DEL;
	palabras["info"] = PALABRA::INFO;
	palabras["clean"] = PALABRA::CLEAN;
	palabras["help"] = PALABRA::HELP;
	palabras["sort"] = PALABRA::SORT;

	DataManagement datos("elements.dat");
	Player jugador;
	Input entrada(datos, jugador);

	int flag = 0;
	int flag2 = 0;
	int n1, n2;
	int score = 0;

	//Preparamos el output del juego
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


	//Bucle principal del juego con el que mantentemos la partida corriendo constantemente
	do {
		std::string command = "";
		std::string parameter = "";

		std::string input;
		bool param = false;
		bool numbers;


		//Mostramos por pantalla la puntuación del jugador y su inventario
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "Your current score: " << jugador.getScore() << std::endl;
		std::cout << "You have these elements: " << std::endl;

		
		for (int i=0; i < jugador.getInventorySize(); i++) { 
			std::cout << i+1 << ": " << jugador.getStringElement(i) << std::endl;	
		}
		

		//Bucle secundario del juego donde hacemos comprobación de ordenes y operaciones lógicas
		do {

			//Pedimos la entrada de ordenes para el juego
			std::cout << std::endl << "What do you want to do?" << std::endl;
			std::getline(std::cin, input);
			std::size_t pos = input.find(" ");
			
			//Tratamos la entrada de datos desde teclado
			if (pos != std::string::npos) {
				command = input.substr(0, pos);
				parameter = input.substr(pos + 1);
				param = true;
			}
			else {
				command = input;
				param = false;
			}

			//Creamos un nuevo elemento, comprobando independientemente del orden en el que pongamos los elementos
			if (atoi(command.c_str()) != 0) {
				//Parse string -> int 
				n1 = atoi(command.c_str());
				n2 = atoi(parameter.c_str());

				//Comprobación de combinación introducida con el archivo que hace de BBDD
				for (auto it = datos.mapa.begin(); it != datos.mapa.end(); it++) {
					if (((it->second.first == jugador.getStringElement(n1-1)) && (it->second.second == jugador.getStringElement(n2 - 1))) || (it->second.first == jugador.getStringElement(n2 - 1)) && (it->second.second == jugador.getStringElement(n1 - 1)))
					{
							jugador.pushToInv(it->first);
							flag2 = 1;
							if (jugador.notInDesc(it->first))
							{
								score++;
								jugador.setScore(score);
								jugador.pushToDesc(it->first);
							}
							break;
					}
				}
			}
			else {
				//Comprobación de ordenes introducidas
				if (palabras.count(command) == 0)
				{
					std::cout << "Command unrecognized. Please type help to see the list of commands." << std::endl;
					flag2 = 0;
				}
				else {
					flag2 = 1;
				}

				//Llamadas a todos los métodos necesarios para el juego, cada uno con su correspondiente clase
				switch (palabras[command])
				{
				case PALABRA::ADD:
					if (parameter == "basics") {
						jugador.addBasics();
					}
					else {
						jugador.addElement(std::stoi(parameter) - 1);
					}
					break;
				case PALABRA::DEL:
					jugador.delElement(std::stoi(parameter) - 1);
					break;
				case PALABRA::INFO:
					entrada.info(std::stoi(parameter) - 1);
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

			}
			
			
		} while (flag2==0);
					
		
	} while (flag!=1);
}