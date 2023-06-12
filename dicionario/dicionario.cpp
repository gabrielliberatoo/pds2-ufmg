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
    else{throw excecaoDicionarioVazio();}
}

string Dicionario::valor(string chave){
    if(pertence(chave)==true){
        for (auto it = elementos_.begin();it!=elementos_.end();it++){
            if(it->chave==chave){
                return it->valor;
            }
        }
    }
    else{throw naoContemChave(chave);}
}

void Dicionario::Inserir(string chave, string valor){
    if(pertence(chave)==false){
        Elemento novo;
        novo.chave=chave;
        novo.valor=valor;

        elementos_.push_back(novo);
    }
    else{throw contemChave(chave);}
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
    else{throw naoContemChave(chave);}
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
    else{throw naoContemChave(chave);}
}

Dicionario::~Dicionario(){}

excecaoDicionarioVazio::excecaoDicionarioVazio(){}

void excecaoDicionarioVazio::msg1(){
     cout << "Não foi possível realizar a operação: Dicionário vazio" << endl;
}

naoContemChave::naoContemChave(string chave1){
    chave = chave1;
}

void naoContemChave::msg2(string chave){
    cout << "Não foi possível realizar a operação: A chave "  << chave << " não está no dicionário" << endl;

}

contemChave::contemChave(string chave1){
    chave = chave1;
}

void contemChave::msg3(string chave){
    cout << "Não foi possível realizar a operação: A chave " << chave << " já está no dicionário" << endl;  
}   