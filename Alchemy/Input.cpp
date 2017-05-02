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
	//Buscamos el nombre del elemento a partir del entero recibido por parámetro
	std::string elemento = p.getStringElement(nElemento);
	//Preparamos la cadena y la convertimos al formato conveniente
	std::string url = "https://en.wikipedia.org/wiki/"+elemento;
	char * cadena = new char[url.length() + 1];
	strcpy_s(cadena,strlen(cadena), url.c_str());

	//Llamamos a la funcion para ejecutar aplicaciones externas
	ShellExecuteA(nullptr, "open", cadena, nullptr, nullptr, SW_SHOWNORMAL);

}

void Input::help()
{
	//Mostramos la salida por pantalla
	std::string tmp;
	std::cout << "Lista de comandos: " << std::endl;
	std::cout << "ADD + elemento  :  Añade una copia de un elemento existente en tu inventario." << std::endl;
	std::cout << "ADD BASICS  :  Añade una copia de los cuatro elementos basicos a tu inventario." << std::endl;
	std::cout << "DELETE + elemento  :  Elimina el elemento de tu inventario." << std::endl;
	std::cout << "CLEAN  :  Elimina los elementos duplicados de tu inventario." << std::endl;
	std::cout << "SORT  :  Ordena tu inventario por orden alfabetico." << std::endl;
	std::cout << "INFO + elemento  :  Accede a Wikipedia para conseguir informacion sobre el elemento." << std::endl;
	std::cout << "HELP  :  Muestra el menu de comandos disponibles." << std::endl;
	std::cout << std::endl << "Press ENTER to continue. " << std::endl;
	std::cin >> tmp;
}
