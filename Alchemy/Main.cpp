#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include "DataManagement.h"


void main() {


	//Bucle para recorrer todo el unordered_map

	/*for (auto it = mapa.begin(); it != mapa.end(); it++) {
		std::cout << it->first  << " //// "<< it->second.first << " - " << it->second.second << std::endl;
	}*/

	DataManagement datos("elements.dat");

	/*for (auto it = datos.mapa.begin(); it != datos.mapa.end(); it++) {
		std::cout << it->first << " //// " << it->second.first << " - " << it->second.second << std::endl;
	}*/
	

}