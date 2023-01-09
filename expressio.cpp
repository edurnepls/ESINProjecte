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
/*
expressio::expressio(const list<token> & l) throw(error)
{
	 try {
        for(auto i = l.begin(); i!= l.end(); i++) {
            token::tipus c = i->tipus();
            if(c == NULLTOK or c == CT_ENTERA or c == CT_RACIONAL or c == CT_REAL or c == CT_E or c == VARIABLE or c == VAR_PERCENTATGE) {
                
            } else throw(ErrorSintactic);
        }
    }
    	catch (...) {
		std::cout << "Error::expressio:31:Error sintactic." << std::endl;
	}
}

// Constructora per còpia, assignació i destructora.
expressio::expressio(const expressio & e) throw(error)
{
	_arrel = e.arrel;
	copia_arbre(e);
}

expressio& expressio::operator=(const expressio & e) throw(error)
{
	_arrel = e._arrel;
	_arrel->set_token(this);
	_arrel->set_list(this);
    return *this;
}

expressio::~expressio() throw(error)
{
	destrueix_arbre(_arrel);
}

expressio& expressio::operator=(expressio && e) throw(error){
	_arrel = e._arrel;
	return *this;
}

// Retorna cert si i només si s'aplica a l'expressió buida.
bool expressio::operator bool() const throw()
{
	if (_arrel == nullptr) {
		return true;
	} else return false;
}*/