#include "DataManagement.h"



DataManagement::DataManagement(std::string url)
{
	std::ifstream archivo;
	std::string linia;

	std::string separaciones[3];
	std::size_t pos;
	std::size_t pos1;

	archivo.open(url);
	while (!archivo.eof())
	{
		std::getline(archivo, linia);

		pos = linia.find("=");
		separaciones[0] = linia.substr(0, pos - 1);
		pos1 = linia.find("+");
		separaciones[1] = linia.substr(pos + 2, (pos1 - 3) - pos);
		separaciones[2] = linia.substr(pos1 + 2);

		mapa[separaciones[0]] = { separaciones[1], separaciones[2] };
	}
}

DataManagement::~DataManagement()
{
}
