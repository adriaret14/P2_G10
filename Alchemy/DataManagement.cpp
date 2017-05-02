#include "DataManagement.h"



DataManagement::DataManagement(std::string url)
{

	//Creamos variables necesarias
	std::ifstream archivo;
	std::string linia;

	std::string separaciones[3];
	std::size_t pos;
	std::size_t pos1;

	//Abrimos el archivo que actuará de BBDD
	archivo.open(url);
	
	//Controlamos el error al abrir el archivo
	if (archivo.fail())
	{
		system("pause");
	}
	else {

		//Recorremos todo el archivo leyendo linea a linea 
		while (!archivo.eof())
		{
			std::getline(archivo, linia);

			//Tratamos las lineas leídas para trocearlas y utilizarlas a nuestro gusto
			pos = linia.find("=");
			separaciones[0] = linia.substr(0, pos - 1);
			pos1 = linia.find("+");
			separaciones[1] = linia.substr(pos + 2, (pos1 - 3) - pos);
			separaciones[2] = linia.substr(pos1 + 2);

			//Guardamos todos los datos en el container STL unordered_map<std::string, std::pair<std::string, std::string>>
			mapa[separaciones[0]] = { separaciones[1], separaciones[2] };
		}
	}
	
	//Cerramos el archivo
	archivo.close();
}

DataManagement::~DataManagement()
{
}
