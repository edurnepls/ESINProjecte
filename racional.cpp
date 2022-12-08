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
  	return num%den;
  }

  /* Sobrecàrrega d'operadors aritmètics. Retorna un racional en la seva
     versió simplificada amb el resultat de l'operació. Es produeix un
     error al dividir dos racionals si el segon és 0.*/
  racional racional::operator+(const racional & r) const throw(error) //falta error si el segon racional és 0
  {
  	   racional nR;
     	if(den == r.den) {
     		nR.num = num + r.num;
     		nR.den = den;
     	} else {
     		nR.den = mcm(2,r.den, den); 
         r.num *= (nR.den%r.den);
         num *= (nR.den%den);
         nR.num = r.num + num;
     	}
      simp(2,nR,0,0);
      return nR;
  }
  racional racional::operator-(const racional & r) const throw(error)
  {
      racional nR;
      if(den == r.den) {
         nR.num = num - r.num;
         nR.den = den;
      } else {
         nR.den = mcm(2,r.den, den); 
         r.num *= (nR.den%r.den);
         num *= (nR.den%den);
         nR.num = r.num - num;
      }
      simp(2,nR,0,0);
      return nR;
  }
  racional racional::racional::operator*(const racional & r) const throw(error)
  {
      racional nR;
      nR.num = num * r.num;
      nR.den = den * r.den;
      simp(2,nR,0,0);
      return nR;
  }
  racional racional::operator/(const racional & r) const throw(error)
  {
      racional nR;
      nR.num = num * r.den;
      nR.den = den * r.num;
      simp(2,nR,0,0);
      return nR;
  }

  /* Sobrecàrrega de operadors de comparació. Retornen cert, si i només si
     el racional sobre el que s'aplica el mètode és igual (==), diferent
     (!=), menor (<), menor o igual (<=), major (>) o major o igual(>=)
     que el racional r.*/
  bool racional::operator==(const racional & r) const throw()
  {
      return num == r.num and den == r.den;
  }
  bool racional::operator!=(const racional & r) const throw()
  {
      return num != r.num and den != r.den;
  }
  bool racional::operator<(const racional & r) const throw()
  {
      bool b = false;
      if((num/den) < (r.num/r.den)) b = true;
      return b;
  }
  bool racional::operator<=(const racional & r) const throw()
  {
      bool b = false;
      if((num/den) <= (r.num/r.den)) b = true;
      return b;
  }
  bool racional::operator>(const racional & r) const throw()
  {
      bool b = false;
      if((num/den) > (r.num/r.den)) b = true;
      return b;
  }
  bool racional::operator>=(const racional & r) const throw()
  {
      bool b = false;
      if((num/den) >= (r.num/r.den)) b = true;
      return b;
  }