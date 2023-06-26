#include "racional.h"
#include <string.h>
#include <istream>
#include <math.h>


int Mdc(int num1, int num2)
{
    if(num1%num2 == 0)
        return num2;
    else
        return Mdc(num2, num1%num2);
}

int Mmc(int a, int b) {
    
    if (a == 0 || b == 0) {
        return 0;
    }
    return abs(a * b) / Mdc(a, b); 
}

void Racional::Simplificar() {
    if (denominador_ < 0) {
        numerador_ = -numerador_;
        denominador_ = -denominador_;
        }
   int denom;
    denom = Mdc(numerador_,denominador_);
    numerador_/=denom;
    denominador_/=denom;
}

Racional::Racional(){
    numerador_=0;
    denominador_=1;
    }

Racional::Racional(int n){
    numerador_= n;
    denominador_ = 1;
    }

Racional::Racional(int n, int d){
    if(d!=0){
        numerador_ = n;
        denominador_ = d;
    }
    else{throw ExcecaoDivisaoPorZero();}
}

int Racional::numerador() const{
    return numerador_;
}

int Racional::denominador() const{
    return denominador_;
}

Racional::operator float()const{
    return static_cast<float>(numerador_) / static_cast<float>(denominador_);
}

Racional::operator string() const{
    string numerador = std::to_string(numerador_);
    string denominador = std::to_string(denominador_);

    return numerador + "/" + denominador;
}

Racional Racional::operator-() const{
    Racional simetrico(-(numerador_), denominador_);
    return simetrico;
}

Racional Racional::operator+(Racional k) const{
    Racional novo;
    if(k.denominador_ == denominador_){
        novo.numerador_ = numerador_ + k.numerador_;
        novo.denominador_ = k.denominador_;
    }   
    else{
        int mmc = k.denominador_ * denominador_;
        novo.numerador_ = ((mmc/denominador_)*numerador_) + ((mmc/k.denominador_)*k.numerador_);
        novo.denominador_ = mmc;
    }
    novo.Simplificar();
    return novo;
}

Racional Racional::operator-(Racional K) const{
Racional novo;
    if(denominador_ == K.denominador_){
        novo.numerador_ = numerador_ - K.numerador_;
        novo.denominador_ = K.denominador_;
    }   
    else{
        int mmc = K.denominador_ * denominador_;
        novo.numerador_ = ((mmc/denominador_)*numerador_) - ((mmc/K.denominador_)*K.numerador_);
        novo.denominador_ = mmc;
    }
    novo.Simplificar();
    return novo;

}

Racional Racional::operator*(Racional k)const{
    Racional novo;
    novo.numerador_ = k.numerador_ * numerador_;
    novo.denominador_ = k.denominador_ * denominador_;
    novo.Simplificar();
    return novo;

}

Racional Racional::operator/(Racional k) const{
    Racional novo;
    if(k.denominador_!=0 && denominador_!=0){
    novo.numerador_ = numerador_ * k.denominador_;
    novo.denominador_ = denominador_ * k.numerador_;
    }
    else{throw ExcecaoDivisaoPorZero();}
    novo.Simplificar();
    return novo;
}

std::ostream& operator<<(std::ostream& out, Racional r){
    out << r.numerador_ << "/" << r.denominador_;
    return out;
}

std::istream& operator>>(std::istream& in, Racional& r) {
  in >> r.numerador_ >>  r.denominador_;
  return in;
}
