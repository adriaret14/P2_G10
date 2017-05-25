#pragma once
#include <string>
#include <unordered_map>
#include <fstream>

template<>
struct std::hash<std::pair<std::string, std::string>>
{
	size_t operator()(const std::pair<std::string, std::string> &pair) const
	{
		return ((std::hash<std::string>()(pair.first) ^ (std::hash<std::string>()(pair.second) << 1)) >> 1);
	}
};

class DataManagement
{
public:
	DataManagement(std::string);													//Constructor de la clase DataManagement
	~DataManagement();																//Destructor de la clase DataManagement

	std::unordered_map<std::pair<std::string, std::string>, std::string>mapa;		//Lista con todas las combinaciones disponibles
};