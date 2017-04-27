#include "Input.h"


Input::Input(DataManagement &data, Player &player):
	dm(data),
	p(player)
{
}

Input::~Input()
{
}


void Input::info(int nElemento)
{
	std::string elemento = p.getStringElement(nElemento);
	std::string url = "https://en.wikipedia.org/wiki/"+elemento;
	//std::string cadena;
	char * cadena = new char[url.length() + 1];
	//std::strcpy(cadena, url.c_str());
	strcpy_s(cadena,strlen(cadena), url.c_str());

	ShellExecuteA(nullptr, "open", cadena, nullptr, nullptr, SW_SHOWNORMAL);

}

void Input::sort()
{
	bool flag = true;
	for (std::vector<std::string>::iterator that = p.getInv().begin() + 1; that != p.getInv().end(); ++that) {
		flag = false;
		for (std::vector<std::string>::iterator it = p.getInv().begin(); it != p.getInv().end(); ++it) {
			if (*(it + 1) < *it) {
				std::string temp = *it;
				*it = *(it + 1);
				*(it + 1) = temp;
				flag = true;
			}
		}
	}
}

void Input::clean()
{
	bool flag = false;
	std::vector<std::string>tmp;
	for (std::vector<std::string>::iterator it = p.getInv().begin(); it != p.getInv().end(); ++it)
	{
		for (std::vector<std::string>::iterator that = p.getInv().begin(); that != p.getInv().end(); ++that) {
			if (*it == *that)
			{
				flag = true;
			}
		}
		if (flag)
		{
			p.getInv().erase(it);
			flag = false;
			it--;
		}
		else
		{
			tmp.push_back(*it);
		}
	}
}

void Input::help()
{
	std::string tmp;
	std::cout << "Lista de comandos: " << std::endl;
	std::cout << "ADD + elemento  :  A�ade una copia de un elemento existente en tu inventario." << std::endl;
	std::cout << "ADD BASICS  :  A�ade una copia de los cuatro elementos basicos a tu inventario." << std::endl;
	std::cout << "DELETE + elemento  :  Elimina el elemento de tu inventario." << std::endl;
	std::cout << "CLEAN  :  Elimina los elementos duplicados de tu inventario." << std::endl;
	std::cout << "SORT  :  Ordena tu inventario por orden alfabetico." << std::endl;
	std::cout << "INFO + elemento  :  Accede a Wikipedia para conseguir informacion sobre el elemento." << std::endl;
	std::cout << "HELP  :  Muestra el menu de comandos disponibles." << std::endl;
	std::cout << std::endl << "Press ENTER to continue. " << std::endl;
	std::cin >> tmp;
}
