#include "dicionario.h"

Dicionario::Dicionario(){
}

int Dicionario::tamanho(){
    return elementos_.size();
}

bool Dicionario::pertence(string chave){
  for (auto it = elementos_.begin();it != elementos_.end(); it++){
    if(it->chave==chave){
        return true;
    }
  }
  return false;
}

string Dicionario::menor(){
    if(tamanho()!=0){
        auto menor=elementos_.begin();;
        for (auto it = elementos_.begin() ;it!=elementos_.end();it++){
            if(menor->chave > it->chave){
                menor = it;
            }
        }
        return menor->chave;
    }
    return "";
}

string Dicionario::valor(string chave){
    if(pertence(chave)==true){
        for (auto it = elementos_.begin();it!=elementos_.end();it++){
            if(it->chave==chave){
                return it->valor;
            }
        }
    }
    return "";
}

void Dicionario::Inserir(string chave, string valor){
    if(pertence(chave)==false){
        Elemento novo;
        novo.chave=chave;
        novo.valor=valor;

        elementos_.push_back(novo);
    }
}

void Dicionario::Remover(string chave){
    if(pertence(chave)==true){
        for(auto it = elementos_.begin();it!=elementos_.end();it++){
            if(it->chave==chave){
                elementos_.erase(it);
                break;
            }
        }
    }
}

void Dicionario::Alterar(string chave, string valor){
    if(pertence(chave)==true){
        for(auto it = elementos_.begin();it!=elementos_.end();it++){
            if(it->chave==chave){
                it->valor=valor;
                break;
            }
        }
    }
}

Dicionario::~Dicionario(){}