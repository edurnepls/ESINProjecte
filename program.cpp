#include "token.hpp"
#include <iostream>
using namespace std;

void print_tp(int c)
{
	const string cod[] = {"NULLTOK","CT_ENTERA", "CT_RACIONAL", "CT_REAL", "CT_E","VARIABLE", 
						"VAR_PERCENTATGE", "SUMA", "RESTA", "MULTIPLICACIO", "DIVISIO", "EXPONENCIACIO",
             			"CANVI_DE_SIGNE", "SIGNE_POSITIU","SQRT", "EXP", "LOG", "EVALF", "OBRIR_PAR", 
             			"TANCAR_PAR", "COMA", "ASSIGNACIO", "DESASSIGNACIO", "BYEBYE"}; 
    std::cout << cod[c] << std::endl;
}

int main()
{
	token t1(-17);
	token t2(89);
	print_tp(t1.tipus()); print_tp(t2.tipus());
	cout << t1.valor_enter() << ' ' << t2.valor_enter() << endl;
	if(t1 == t2) cout << "true" << endl;
	else cout << "false" << endl;
	/*print_tp(t.tipus());
	cout << t.valor_enter() << endl;
	//valor racional
	racional r = t.valor_racional();
	cout << t.valor_real() << endl;
	cout << t.identificador_variable() << endl;*/
}
/*{
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