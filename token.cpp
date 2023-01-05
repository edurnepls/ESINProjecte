#include "token.hpp"

//Constructores
token::token(codi cod) throw(error)
{
	try {
		if(cod != CT_ENTERA and cod != CT_RACIONAL and cod != CT_REAL and cod != VARIABLE) {
			_s = cod;
		} else {
			throw error(ConstructoraInadequada);
		}
	}
	catch (...){
		std::cout << "Error::token:12:La constructora per aquest token no es l'adequada." << std::endl;
	}
}

token::token(int n) throw(error)
{
	try {
		p_element = new int;
		*(int*)p_element = n;
		_s = CT_ENTERA;
	}
	catch (...) {
		std::cout << "Error::token:12:La constructora per aquest token no es l'adequada." << std::endl;
	}
}

token::token(const racional & r) throw(error)
{
	try {
		racional n = r;
		p_element = new racional;
		*(racional*)p_element = n;
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
		*(double*)p_element = x;
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
			string n = var_name;
			p_element = new string;
			*(string*)p_element = n;
			_s = VARIABLE;
		} else throw error(IdentificadorIncorrecte);
	}
	catch (...) {
		std::cout << "Error::token:11:El nom de la variable no es valid." << std::endl;
	}
}

//Constructora por còpia, assignació i destructora
token::token(const token & t) throw (error)
{
	_s = t._s;
	p_element = t.p_element;
}

token& token::operator=(const token & t) throw(error)
{
	_s = t._s;
	p_element = t.p_element;
	return *this;
}

token::~token() throw()
{
	delete(p_element);
	_s = NULLTOK;
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
	int ret;
	try {
		if (_s == CT_ENTERA) {
			ret = *(int *)p_element;
		} else throw error(ConsultoraInadequada);
	}
	catch (...) {
		std::cout << "Error::token:13:Aquesta consultora del token no es apropiada." << std::endl;
	}
	return ret;
}

racional token::valor_racional() const throw(error)
{
	racional ret;
	try {
		if (_s == CT_RACIONAL) {
			ret = *(racional*)p_element;
		} else throw error(ConsultoraInadequada);
	}
	catch (...) {
		std::cout << "Error::token:13:Aquesta consultora del token no es apropiada." << std::endl;
	}
	return ret;
}

double token::valor_real() const throw(error)
{
	double ret;
	try {
		if (_s == CT_REAL) {
			ret = *((double*)p_element);
		} else throw error(ConsultoraInadequada);
	}
	catch (...) {
		std::cout << "Error::token:13:Aquesta consultora del token no es apropiada." << std::endl;
	}
	return ret;
}

string token::identificador_variable() const throw(error)
{
	string ret;
	try {
		if (_s == VARIABLE) {
			ret = *((string*)p_element);
		} else throw error(ConsultoraInadequada);
	}
	catch (...) {
		std::cout << "Error::token:13:Aquesta consultora del token no es apropiada." << std::endl;
	}
	return ret;
}

//Igualtat i desigualtat entre tokens
bool token::operator==(const token & t) const throw()
{
	if(_s == t._s) { //són iguals; comparem
		if(_s == CT_ENTERA) { //int
			return *((int *)p_element) == *((int *)t.p_element); 
		} 
		else if (_s == CT_RACIONAL) { //racional
			racional r1 = *(racional *)p_element, r2 = *(racional *)t.p_element;
			return ((r1.num() == r2.num()) and (r1.denom() == r2.denom()));
		}
		else if (_s == CT_REAL) { //real
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
	if(_s != t._s) {
		if(_s == CT_ENTERA) { //int
			return *((int *)p_element) != *((int *)t.p_element); 
		} 
		else if (_s == CT_RACIONAL) { //racional
			racional r1 = *(racional *)p_element, r2 = *(racional *)t.p_element;
			return ((r1.num() != r2.num()) and (r1.denom() != r2.denom()));
		}
		else if (_s == CT_REAL) { //real
			return *((double *)p_element) != *((double *)t.p_element);
		}
		else { //variable o operadors, funcions predefinides, noms de comandes o símbols de ``puntuació''
			return *((string *)p_element) != *((string *)t.p_element);
		}
	}
	return false;
}

//Precedència entre tokens
bool token::operator>(const token & t) const throw(error)
{
	bool gran = true;
	try {
		if((_s > 6 and _s < 14) and (t._s > 6 and t._s < 14)) {
			if(_s == t._s) gran = false; 
			else if(_s == EXPONENCIACIO) gran = true;
			else if(t._s == EXPONENCIACIO) gran = false;
			else if(_s == CANVI_DE_SIGNE and t._s != EXPONENCIACIO) gran = true;
			else if(_s == CANVI_DE_SIGNE and t._s == EXPONENCIACIO) gran = false;
			else if(_s == SIGNE_POSITIU and (t._s != EXPONENCIACIO
										and t._s != CANVI_DE_SIGNE)) gran = true;
			else if(_s == SIGNE_POSITIU and (t._s == EXPONENCIACIO 
										or t._s == CANVI_DE_SIGNE)) gran = false;
			else if(_s == MULTIPLICACIO and (t._s != EXPONENCIACIO
										and t._s != CANVI_DE_SIGNE
										and t._s != SIGNE_POSITIU)) gran = true;
			else if(_s == MULTIPLICACIO and (t._s == EXPONENCIACIO
										or t._s == CANVI_DE_SIGNE
										or t._s == SIGNE_POSITIU)) gran = false;
			else if(_s == DIVISIO and (t._s != EXPONENCIACIO
									and t._s != CANVI_DE_SIGNE
									and t._s != SIGNE_POSITIU
									and t._s != MULTIPLICACIO)) gran = true;
			else if(_s == DIVISIO and (t._s == EXPONENCIACIO
									or t._s == CANVI_DE_SIGNE
									or t._s == SIGNE_POSITIU
									or t._s == MULTIPLICACIO)) gran = false;
			else if(_s == SUMA and (t._s != EXPONENCIACIO
								and t._s != CANVI_DE_SIGNE
								and t._s != SIGNE_POSITIU
								and t._s != MULTIPLICACIO
								and t._s != DIVISIO)) gran = true;
			else if(_s == SUMA and (t._s == EXPONENCIACIO
								or t._s == CANVI_DE_SIGNE
								or t._s == SIGNE_POSITIU
								or t._s == MULTIPLICACIO
								or t._s == DIVISIO)) gran = false;
			else gran = false; //this->_s == RESTA; sempre serà fals
		}
		else throw error(PrecedenciaEntreNoOperadors);
	}
	catch (...) {
		std::cout << "Error::token:14:La precedencia es defineix entre operadors." << std::endl;
	}
	return gran;
}

bool token::operator<(const token & t) const throw(error)
{
	bool petit = true;
	try {
		if((_s > 6 and _s < 14) and (t._s > 6 and t._s < 14)) {
			if(_s == t._s) petit = false; 
			else if(_s == EXPONENCIACIO) petit = false;
			else if(t._s == EXPONENCIACIO) petit = true;
			else if(_s == CANVI_DE_SIGNE and t._s != EXPONENCIACIO) petit = false;
			else if(_s == CANVI_DE_SIGNE and t._s == EXPONENCIACIO) petit = true;
			else if(_s == SIGNE_POSITIU and (t._s != EXPONENCIACIO
										and t._s != CANVI_DE_SIGNE)) petit = false;
			else if(_s == SIGNE_POSITIU and (t._s == EXPONENCIACIO 
										or t._s == CANVI_DE_SIGNE)) petit = true;
			else if(_s == MULTIPLICACIO and (t._s != EXPONENCIACIO
										and t._s != CANVI_DE_SIGNE
										and t._s != SIGNE_POSITIU)) petit = false;
			else if(_s == MULTIPLICACIO and (t._s == EXPONENCIACIO
										or t._s == CANVI_DE_SIGNE
										or t._s == SIGNE_POSITIU)) petit = true;
			else if(_s == DIVISIO and (t._s != EXPONENCIACIO
									and t._s != CANVI_DE_SIGNE
									and t._s != SIGNE_POSITIU
									and t._s != MULTIPLICACIO)) petit = false;
			else if(_s == DIVISIO and (t._s == EXPONENCIACIO
									or t._s == CANVI_DE_SIGNE
									or t._s == SIGNE_POSITIU
									or t._s == MULTIPLICACIO)) petit = true;
			else if(_s == SUMA and (t._s != EXPONENCIACIO
								and t._s != CANVI_DE_SIGNE
								and t._s != SIGNE_POSITIU
								and t._s != MULTIPLICACIO
								and t._s != DIVISIO)) petit = false;
			else if(_s == SUMA and (t._s == EXPONENCIACIO
								or t._s == CANVI_DE_SIGNE
								or t._s == SIGNE_POSITIU
								or t._s == MULTIPLICACIO
								or t._s == DIVISIO)) petit = true;
			else petit = false; //this->_s == RESTA; sempre serà fals
		}
		else throw error(PrecedenciaEntreNoOperadors);
	}
	catch (...) {
		std::cout << "Error::token:14:La precedencia es defineix entre operadors." << std::endl;
	}
	return petit;
}

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
