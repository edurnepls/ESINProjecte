#include "expressio.hpp"

expressio::expressio(const token t) throw(error)
{
	try {
		token::codi c = t.tipus();
		if(c == NULLTOK or c == CT_ENTERA or c == CT_RACIONAL or c == CT_REAL or c == CT_E or c == VARIABLE or c == VAR_PERCENTATGE) {
			
		} else throw(ErrorSintactic);
	}
	catch (...) {
		std::cout << "Error::expressio:31:Error sintactic." << std::endl;
	}
}