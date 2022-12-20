#include "token.hpp"

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
		_s = "CT_ENTERA";
		_t.x = n;
	}
	catch (...) {
		std::cout << "Error::token:12:La constructora per aquest token no es l'adequada." << std::endl;
	}
}