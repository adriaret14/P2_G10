#pragma once
#include <string>
#include <unordered_map>
#include <fstream>

class DataManagement
{
public:
	DataManagement(std::string);
	~DataManagement();

	std::unordered_map<std::string, std::pair<std::string, std::string>>mapa;
};

