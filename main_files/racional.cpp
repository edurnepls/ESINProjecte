#include "racional.hpp"

// Constructora. Construeix un racional en la seva versió simplificada.
  // Es produeix un error si el denominador és 0.
  explicit racional::racional(int n=0, int d=1) throw(error)
  {
  	num = n;
  	den = d;
  }

  // Constructora per còpia, assignació i destructora.
  racional::racional(const racional & r) throw(error)
  {
  	num = r.num;
  	den = r.den;
  }
  racional & racional::operator=(const racional & r) throw(error)
  {
  	num = r.num;
  	den = r.den;
  }
  racional::~racional() throw()
  {}

  // Consultores. La part_entera d'un racional pot ser
  // positiva o negativa. El residu SEMPRE és un racional positiu.
  int racional::num() const throw()
  {
  	return num;
  }
  int racional::denom() const throw()
  {
  	return den;
  }
  int racional::part_entera() const throw()
  {
  	return num/den;
  }
  racional racional::residu() const throw()
  {
  	
  }

  /* Sobrecàrrega d'operadors aritmètics. Retorna un racional en la seva
     versió simplificada amb el resultat de l'operació. Es produeix un
     error al dividir dos racionals si el segon és 0.*/
  racional racional::operator+(const racional & r) const throw(error)
  {
  	racional nR;
  	if(den == r.den) {
  		nR.num = num + r.num;
  		nR.den = den;
  	} else {
  		
  	}
  }
  racional racional::operator-(const racional & r) const throw(error);
  racional racional::racional::operator*(const racional & r) const throw(error);
  racional racional::operator/(const racional & r) const throw(error);

  /* Sobrecàrrega de operadors de comparació. Retornen cert, si i només si
     el racional sobre el que s'aplica el mètode és igual (==), diferent
     (!=), menor (<), menor o igual (<=), major (>) o major o igual(>=)
     que el racional r.*/
  bool racional::operator==(const racional & r) const throw();
  bool racional::operator!=(const racional & r) const throw();
  bool racional::operator<(const racional & r) const throw();
  bool racional::operator<=(const racional & r) const throw();
  bool racional::operator>(const racional & r) const throw();
  bool racional::operator>=(const racional & r) const throw();