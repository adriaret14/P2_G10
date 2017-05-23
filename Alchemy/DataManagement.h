#pragma once
#include <string>
#include <unordered_map>
#include <fstream>

class DataManagement
{
public:
	DataManagement(std::string);													//Constructor de la clase DataManagement
	~DataManagement();																//Destructor de la clase DataManagement

	std::unordered_map<std::pair<std::string, std::string>, std::string>mapa;		//Lista con todas las combinaciones disponibles
};

