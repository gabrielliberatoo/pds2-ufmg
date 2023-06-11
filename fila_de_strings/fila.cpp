#include "fila.h"
#include <string>


Fila::Fila(){
    primeiro_ = nullptr;
    ultimo_ = nullptr;
}

string Fila::primeiro(){
    if(!vazia()){
        return primeiro_->chave;
    }
}

string Fila::ultimo(){
    if(!vazia()){
        return ultimo_->chave;
    }
}

bool Fila::vazia(){
    return primeiro_ == nullptr;
}

void Fila::Inserir(string k){
    No* no = new No;
    no->chave = k;
    no->proximo = nullptr;

    if(vazia()){
        primeiro_ = no;
        ultimo_ = no;
    }
    else{
        ultimo_->proximo = no;
        ultimo_ = no;
    }
}

void Fila::Remover(){ 
    if(!vazia()){
        No* remover = primeiro_;
        primeiro_ = primeiro_->proximo;
        
        if (primeiro_ == nullptr) {
            ultimo_ = nullptr; // Atualiza o ponteiro 'ultimo_' quando a fila fica vazia
        }
        delete remover;
    }
}

int Fila::tamanho(){
    if(vazia()){
        return 0;
    }

    No* contagem = primeiro_;
    int tam = 0;

    while(contagem != nullptr){
        tam++;
        contagem = contagem->proximo;
    }
    return tam;
}

Fila::~Fila(){
    while(!vazia()){
        Remover();
    }
}