#include "racional.h"

#include <cmath>
#include <iostream>
#include <numeric>

void Racional::Simplificar() {
  int mdcfun;
  if(denominador_ < 0){
    denominador_ = denominador_ * -1;
  }
  
  if(numerador_%denominador_ == 0){
    mdcfun = denominador_;
  }
  else{mdcfun = mdc(denominador_, numerador_%denominador_);}

  numerador_ = numerador_ / mdcfun;
  denominador_ = denominador_ / mdcfun;

}

Racional::Racional() {
    numerador_ = 0;
    denominador_ = 1;
}

Racional::Racional(int n)  {
    numerador_ = n;
    denominador_ = 1;
}

Racional::Racional(int n, int d) {
    if(d == 0){
      cout << "Denominador invalido!" << endl;
    }
    numerador_ = n;
    denominador_ = d;
    simplificar();
}

int Racional::numerador() const {
  return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::simetrico() const {
  Racional simetrico(numerador_ , denominador_);
  simetrico.denominador_ = denominador_ * -1;
  simetrico.numerador_ = numerador_ * -1;
  return simetrico;

}

Racional Racional::somar(Racional k) const {
  
}

Racional Racional::subtrair(Racional k) const {
  return Racional(k.simetrico());
}

Racional Racional::multiplicar(Racional k) const {
    return Racional(numerador_ * k.numerador(), denominador_ * k.denominador())
}

Racional Racional::dividir(Racional k) const {
    return multiplicar(k.inverso());
}

