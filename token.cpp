#include "token.hpp"

//Constructores
token::token(codi cod) throw(error)
{
	try {
		if((cod < 1 and cod > 3) and cod != 5) {
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
		if() {

		} else throw 11;
	}
	catch (...) {

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
			return *((int*)p_element);
		} else throw 13;
	}
	catch (...) {
		std::cout << "Error::token:13:Aquesta consultora del token no es apropiada." << std::endl;
	}
}

racional valor_racional() const throw(error)
{

}
/*double valor_real() const throw(error);
string identificador_variable() const throw(error);*/
//Igualtat i desigualtat entre tokens

//Precedència entre tokens

//Implementació funcions privades
void token::print_tp() const throw(error)
{
	const string cod[] = {"NULLTOK","CT_ENTERA", "CT_RACIONAL", "CT_REAL", "CT_E","VARIABLE", 
						"VAR_PERCENTATGE", "SUMA", "RESTA", "MULTIPLICACIO", "DIVISIO", "EXPONENCIACIO",
             			"CANVI_DE_SIGNE", "SIGNE_POSITIU","SQRT", "EXP", "LOG", "EVALF", "OBRIR_PAR", 
             			"TANCAR_PAR", "COMA", "ASSIGNACIO", "DESASSIGNACIO", "BYEBYE"}; 
    std::cout << cod[this->_s] << std::endl;
}