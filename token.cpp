#include "token.hpp"

//Constructores
token::token(codi cod) throw(error)
{
	try {
		if((cod < 1 and cod > 3) and cod != 5) {
			p_element = new string;
			_s = cod;
		} else {
			throw (cod);
		}
	}
	catch (codi cod){
		std::cout << "Error::token:12:La constructora per aquest token no es l'adequada." << std::endl;
	}
}

token::token(int n) throw(error)
{
	try {
		p_element = new int;
		p_element = &n;
		_s = CT_ENTERA;
	}
	catch (...) {
		std::cout << "Error::token:12:La constructora per aquest token no es l'adequada." << std::endl;
	}
}

token::token(const racional & r) throw(error)
{
	try {
		p_element = new racional;
		p_element = &r;
		_s = CT_RACIONAL;
	}
	catch (...) {
		std::cout << "Error::token:12:La constructora per aquest token no es l'adequada." << std::endl;
	}
}

token::token(double x) throw(error)
{
	try {
		p_element = new double;
		p_element = &x;
		_s = CT_REAL;
	}
	catch (...) {
		std::cout << "Error::token:12:La constructora per aquest token no es l'adequada." << std::endl;
	}
}

token::token(const string & var_name) throw(error)
{
	try {
		if(this->valid_var(var_name)) {
			p_element = new string;
			p_element = &var_name;
			_s = VARIABLE;
		} else throw 11;
	}
	catch (...) {
		std::cout << "Error::token:11:El nom de la variable no es valid." << std::endl;
	}
}

//Constructora por còpia, assignació i destructora
token::~token() throw()
{

}

//Consultores
token::codi token::tipus() const throw()
{
	try {
		return _s;
	}
	catch (...) {
		std::cout << "Error::token:13:Aquesta consultora del token no es apropiada." << std::endl;
	}
}

int token::valor_enter() const throw(error)
{
	try {
		if (_s == 1) {
			return *(int *)p_element;
		} else throw 13;
	}
	catch (...) {
		std::cout << "Error::token:13:Aquesta consultora del token no es apropiada." << std::endl;
	}
	return 0;
}

racional token::valor_racional() const throw(error)
{
	try {
		if (_s == 2) {
			return *((racional*)p_element);
		} else throw 13;
	}
	catch (...) {
		std::cout << "Error::token:13:Aquesta consultora del token no es apropiada." << std::endl;
	}
}

double token::valor_real() const throw(error)
{
	try {
		if (_s == 3) {
			return *((double*)p_element);
		} else throw 13;
	}
	catch (...) {
		std::cout << "Error::token:13:Aquesta consultora del token no es apropiada." << std::endl;
	}
	return 0;
}

string token::identificador_variable() const throw(error)
{
	try {
		if (_s == 5) {
			return *((string*)p_element);
		} else throw 13;
	}
	catch (...) {
		std::cout << "Error::token:13:Aquesta consultora del token no es apropiada." << std::endl;
	}
}

//Igualtat i desigualtat entre tokens
bool token::operator==(const token & t) const throw()
{
	if(_s == t._s) { //són iguals; comparem
		if(_s == 1) { //int
			return *((int *)p_element) == *((int *)t.p_element); 
		} 
		else if (_s == 2) { //racional
			racional r1 = *(racional *)p_element, r2 = *(racional *)t.p_element;
			return ((r1.num() == r2.num()) and (r1.denom() == r2.denom()));
		}
		else if (_s == 3) { //real
			return *((double *)p_element) == *((double *)t.p_element);
		}
		else { //variable o operadors, funcions predefinides, noms de comandes o símbols de ``puntuació''
			return *((string *)p_element) == *((string *)t.p_element);
		}
	} 
	return false;
}

bool token::operator!=(const token & t) const throw()
{

}
//Precedència entre tokens

//Implementació funcions privades
/*void token::print_tp() const throw(error)
{
	const string cod[] = {"NULLTOK","CT_ENTERA", "CT_RACIONAL", "CT_REAL", "CT_E","VARIABLE", 
						"VAR_PERCENTATGE", "SUMA", "RESTA", "MULTIPLICACIO", "DIVISIO", "EXPONENCIACIO",
             			"CANVI_DE_SIGNE", "SIGNE_POSITIU","SQRT", "EXP", "LOG", "EVALF", "OBRIR_PAR", 
             			"TANCAR_PAR", "COMA", "ASSIGNACIO", "DESASSIGNACIO", "BYEBYE"}; 
    std::cout << cod[this->_s] << std::endl;
}*/
bool token::valid_var(const string & var)
{
	bool valid = true;
	unsigned int i = 0;
	if(var == "unassign" or var == "e" or var == "sqrt" or var == "log" or var == "exp" or var == "evalf") valid = false;
	while(valid and i < var.size()) {
		if((var[i] >= 65 and var[i] <= 90) or (var[i] >= 97 and var[i] <= 122) or var[i] == 95) ++i;
		else valid = false;
	}
	return valid;
}