#include "racional.hpp"
#include <iostream>
using namespace std;

/*int main()
{
	racional x,y,z;
	
	leer("Cuanto vale x?" , x );
	escribir(x);
	leer("Cuanto vale y?" , y );
	escribir(y);

}

void leer(const char *mensaje, racional & r) {
	int a, b;
	std::cout << "Escriba el numerador del racional:" << std::endl;
	std::cin >> a >> std::endl;
	std::cout << "Escriba el denominador del racional:" << std::endl;
	std::cin >> b >> std::endl;
	r._num = a;
	r._den = b;
}

void escribir(const char *mensaje, racional r) {
	cout << "El racional " << r << " es:" << endl;
	cout << r.num() << "/" << r.denom() << endl;
	cout << "Su parte entera es = " << r.part_entera << endl;
	cout << "Y su residuo es = " << r.residu << endl;
}

//Faltan las operaciones, no esta compilado porque esta hecho con visual studio desde mi poratatil.
//Cuando  llegue a casa lo sigo progrmando con linux*/