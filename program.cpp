#include "token.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define MAX_SIZE 100

void print_tp(int c)
{
	const string cod[] = {"NULLTOK","CT_ENTERA", "CT_RACIONAL", "CT_REAL", "CT_E","VARIABLE", 
						"VAR_PERCENTATGE", "SUMA", "RESTA", "MULTIPLICACIO", "DIVISIO", "EXPONENCIACIO",
             			"CANVI_DE_SIGNE", "SIGNE_POSITIU","SQRT", "EXP", "LOG", "EVALF", "OBRIR_PAR", 
             			"TANCAR_PAR", "COMA", "ASSIGNACIO", "DESASSIGNACIO", "BYEBYE"}; 
    std::cout << cod[c] << std::endl;
}

bool is_cod(const string s) {
	const string cod[] = {"NULLTOK","CT_ENTERA", "CT_RACIONAL", "CT_REAL", "CT_E","VARIABLE", 
						"VAR_PERCENTATGE", "SUMA", "RESTA", "MULTIPLICACIO", "DIVISIO", "EXPONENCIACIO",
             			"CANVI_DE_SIGNE", "SIGNE_POSITIU","SQRT", "EXP", "LOG", "EVALF", "OBRIR_PAR", 
             			"TANCAR_PAR", "COMA", "ASSIGNACIO", "DESASSIGNACIO", "BYEBYE"};
    bool trobat = false;
    unsigned int i = 0;
    while(i < sizeof(cod) and !trobat) {
    	if(s == cod[i]) trobat = true;
    	else ++i;
    }
    return trobat;
}

void string_to_cod(const string s, token::codi &cod) {
	if(s == "NULLTOK") cod = token::NULLTOK;
	else if(s == "CT_ENTERA") cod = token::CT_ENTERA;
	else if(s == "CT_RACIONAL") cod = token::CT_RACIONAL;
	else if(s == "CT_REAL") cod = token::CT_REAL;
	else if(s == "CT_E") cod = token::CT_E;
	else if(s == "VARIABLE") cod = token::VARIABLE;
	else if(s == "VAR_PERCENTATGE") cod = token::VAR_PERCENTATGE;
	else if(s == "SUMA") cod = token::SUMA;
	else if(s == "RESTA") cod = token::RESTA;
	else if(s == "MULTIPLICACIO") cod = token::MULTIPLICACIO;
	else if(s == "DIVISIO") cod = token::DIVISIO;
	else if(s == "EXPONENCIACIO") cod = token::EXPONENCIACIO;
	else if(s == "CANVI_DE_SIGNE") cod = token::CANVI_DE_SIGNE;
	else if(s == "SIGNE_POSITIU") cod = token::SIGNE_POSITIU;
	else if(s == "SQRT") cod = token::SQRT;
	else if(s == "EXP") cod = token::EXP;
	else if(s == "LOG") cod = token::LOG;
	else if(s == "EVALF") cod = token::EVALF;
	else if(s == "OBRIR_PAR") cod = token::OBRIR_PAR;
	else if(s == "TANCAR_PAR") cod = token::TANCAR_PAR;
	else if(s == "COMA") cod = token::COMA;
	else if(s == "ASSIGNACIO") cod = token::ASSIGNACIO;
	else if(s == "DESASSIGNACIO") cod = token::DESASSIGNACIO;
	else cod = token::BYEBYE;
}

int main()
{
	token t1(token::CT_E);

	//tipus
	print_tp(t1.tipus());
	//valor_enter
	int *tmp = NULL;
	&tmp = t1.valor_enter();
	if(tmp != NULL) cout << *tmp << endl;
	//valor_racional
	racional r = t1.valor_racional();
	cout << r.num() << '/' << r.denom() << endl;
	//valor_real
	cout << t1.valor_real() << endl;
	//identificador_variable
	cout << t1.identificador_variable() << endl;

	/*string str;
	token Arr_tk[MAX_SIZE];
	unsigned int i = 0;

	while(getline(cin, str)) {
		token tmp; //token temporal que fem servir per accedir al Arr_tk
		try {
			if(i >= 1) tmp = Arr_tk[i-1];
		}
		catch (...) {}

		istringstream ss(str);
		string ord;
		ss >> ord;

		if(ord == "init") { //constructora init
			token T; //token temporal que fem servir per poder guardar el token al Arr_tk
			string name, tipus, val;
			ss >> ord; name = ord;
			ss >> ord; tipus = ord;
			ss >> ord; val = ord;
			if(tipus == "token") { //creando token
				if(is_cod(ord)) { // es codi
					token::codi cod;
					string_to_cod(ord,cod);
					cout << cod << endl;
					token t1(cod);
					T = t1;
				}

				//push t1 en el Arr_tk
				Arr_tk[i] = T;
				++i;
			}
		} 
		else if(ord == "tp") {
			print_tp(tmp.tipus());
		} 
		else if(ord == "ve") {
			cout << tmp.valor_enter() << endl;
		} 
		else if(ord == "vra") {
			racional r_tmp = tmp.valor_racional();
			cout << r_tmp.num() << '/' << r_tmp.denom() << endl;
		} 
		else if(ord == "vre") {
			cout << tmp.valor_real() << endl;
		} 
		else if(ord == "idvar") {
			cout << tmp.identificador_variable() << endl;
		}	
	}*/
	//proves void pointer
	/*int x = 10;
	void *p = &x;
	cout << *((int *)p) << endl;*/
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