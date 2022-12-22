#include "racional.hpp"

// Constructora. Construeix un racional en la seva versió simplificada.
  // Es produeix un error si el denominador és 0.
  racional::racional(int n, int d) throw(error)
  {
      try {
         if (_den != 0) {
            _num = n;
            _den = d;
         } else {
            throw (_den);
         }
      }
      catch(int _den) {
         std::cout << "Error" << std::endl;
      }
  }

  // Constructora per còpia, assignació i destructora.
  racional::racional(const racional & r) throw(error)
  {
     	_num = r._num;
     	_den = r._den;
  }
  racional& racional::operator=(const racional & r) throw(error)
  {
     	_num = r._num;
     	_den = r._den;
      return *this;
  }
  racional::~racional() throw()
  {}

  // Consultores. La part_entera d'un racional pot ser
  // positiva o negativa. El residu SEMPRE és un racional positiu.
  int racional::num() const throw()
  {
  	   return _num;
  }
  int racional::denom() const throw()
  {
  	   return _den;
  }
  int racional::part_entera() const throw()
  {
  	   return _num/_den;
  }
  racional racional::residu() const throw()
  {
  	   racional nR;
      nR._num = _num%_den;
      nR._den = 1;
      return nR; 
  }

  /* Sobrecàrrega d'operadors aritmètics. Retorna un racional en la seva
     versió simplificada amb el resultat de l'operació. Es produeix un
     error al dividir dos racionals si el segon és 0.*/
  racional racional::operator+(const racional & r) const throw(error) //falta error si el segon racional és 0
  {
  	   racional nR;
     	if(_den == r._den) {
     		nR._num = _num + r._num;
     		nR._den = _den;
     	} else {
     		nR._den = mcm(2,r._den,_den);
         nR._num = (r._num*(nR._den%r._den)) + (_num*(nR._den%_den));
     	}
      simp(2,nR,0,0);
      return nR;
  }
  racional racional::operator-(const racional & r) const throw(error)
  {
      racional nR;
      if(_den == r._den) {
         nR._num = _num - r._num;
         nR._den = _den;
      } else {
         nR._den = mcm(2,r._den, _den);
         nR._num = (r._num*(nR._den%r._den)) - (_num*(nR._den%_den));
      }
      simp(2,nR,0,0);
      return nR;
  }
  racional racional::racional::operator*(const racional & r) const throw(error)
  {
      racional nR;
      nR._num = _num * r._num;
      nR._den = _den * r._den;
      simp(2,nR,0,0);
      return nR;
  }
  racional racional::operator/(const racional & r) const throw(error)
  {
      racional nR;
      nR._num = _num * r._den;
      nR._den = _den * r._num;
      simp(2,nR,0,0);
      return nR;
  }

  /* Sobrecàrrega de operadors de comparació. Retornen cert, si i només si
     el racional sobre el que s'aplica el mètode és igual (==), diferent
     (!=), menor (<), menor o igual (<=), major (>) o major o igual(>=)
     que el racional r.*/
  bool racional::operator==(const racional & r) const throw()
  {
      return _num == r._num and _den == r._den;
  }
  bool racional::operator!=(const racional & r) const throw()
  {
      return _num != r._num and _den != r._den;
  }
  bool racional::operator<(const racional & r) const throw()
  {
      bool b = false;
      if((_num/_den) < (r._num/r._den)) b = true;
      return b;
  }
  bool racional::operator<=(const racional & r) const throw()
  {
      bool b = false;
      if((_num/_den) <= (r._num/r._den)) b = true;
      return b;
  }
  bool racional::operator>(const racional & r) const throw()
  {
      bool b = false;
      if((_num/_den) > (r._num/r._den)) b = true;
      return b;
  }
  bool racional::operator>=(const racional & r) const throw()
  {
      bool b = false;
      if((_num/_den) >= (r._num/r._den)) b = true;
      return b;
  }

  //Implementació funcions privades:

void racional::simp(int x, racional & r, int Nn, int Nd) const
{
   if(r._num < 0) {r._num *= -1; Nn = 1;}
   if(r._den < 0) {r._den *= -1; Nd = 1;}

   if(r._num == 0) {
      r._den = 1;
   } else if(x <= r._num and x <= r._den) {
      if(r._num%x == 0 and r._den%x == 0) {
         r._num /= x; r._den /= x;
         simp(x,r,Nn,Nd);
      }
      else simp(x+1,r,Nn,Nd);
   }

   if(Nn == 1) r._num *= -1;
   if(Nd == 1) r._den *= -1;
}

int racional::mcm(int div, int x, int y) const
{
   int aux=1;
   while(x%div==0 || y%div==0)
   {
      aux*=div;
      if(x%div==0) x/=div;
      if(y%div==0) y/=div;
   }
   if(div<=x||div<=y) aux*=mcm(div+1,x,y);
   return aux;
}