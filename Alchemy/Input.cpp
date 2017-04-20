#include "Input.h"



Input::Input()
{
}


Input::~Input()
{
}

void Input::addBasics()
{
	p.addElement("Air");
	p.addElement("Earth");
	p.addElement("Fire");
	p.addElement("Water");
}

void Input::addElement(int i)
{
	p.addElement(p.getInv()[i]);
}

void Input::delElement(int i)
{
	p.delElement(i);
}

void Input::help()
{
	std::cout << "Lista de comandos: " << std::endl;
	std::cout << "ADD + elemento  :  Añade una copia de un elemento existente en tu inventario." << std::endl;
	std::cout << "ADD BASICS  :  Añade una copia de los cuatro elementos basicos a tu inventario." << std::endl;
	std::cout << "DELETE + elemento  :  Elimina el elemento de tu inventario." << std::endl;
	std::cout << "CLEAN  :  Elimina los elementos duplicados de tu inventario." << std::endl;
	std::cout << "SORT  :  Ordena tu inventario por orden alfabetico." << std::endl;
	std::cout << "INFO + elemento  :  Accede a Wikipedia para conseguir informacion sobre el elemento." << std::endl;
	std::cout << "HELP  :  Muestra el menu de comandos disponibles." << std::endl;
}
