#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

void main() {
	
	//Creamos las variables necesarias para abrir el fichero
	std::string linia;
	std::string separaciones[3];
	std::ifstream archivo;
	std::size_t pos;
	std::size_t pos1;
	//Llamamos a la funcion de abrir el fichero
	archivo.open("elements.dat");
	while (!archivo.eof())
	{
		//Guardamos cada linia del archivo en la variable linia
		std::getline(archivo, linia);

		std::cout << linia << std::endl;
		pos=linia.find("=");
		separaciones[0] = linia.substr(0, pos-1);
		pos1 = linia.find("+");
		separaciones[1] = linia.substr(pos + 2, (pos1-2)-pos);
		separaciones[2] = linia.substr(pos1+2);

		std::cout << separaciones[0] << std::endl << separaciones[1] << std::endl << separaciones[2] << std::endl;

	 }


}