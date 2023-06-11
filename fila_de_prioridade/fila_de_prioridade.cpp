#include "fila_de_prioridade.h"
#include <list>
#include <string>
#include <vector>
#include <algorithm>

using std::list;
using std::string;
using std::vector;


void FilaDePrioridade::Adicionar(Pessoa p) {
  lista_.push_back(p);
}

string FilaDePrioridade::RemoverMaiorPrioridade() {   
  list<Pessoa>::iterator it;
  list<Pessoa>::iterator it2;
  string nome;
  while (it != lista_.end())
  {
    it = lista_.begin();
    if(it->prioridade > it2->prioridade){
      it2 = it;
    }
    it++;
  }
  nome = it2 ->nome;
  lista_.erase(it2);  
  return nome;
}

void FilaDePrioridade::Remover(string nome) {
    list<Pessoa>::iterator it;
    for(it = lista_.begin(); it != lista_.end(); ++it){
        if(nome == it->nome){
            lista_.erase(it);
        }
    }
}

int FilaDePrioridade::tamanho() {
  return lista_.size();
}

vector<string> FilaDePrioridade::listar() {
    vector<Pessoa> pessoas;
    vector<string> nomes;

    // percorre a fila e adiciona as pessoas ao vetor auxiliar
    for (auto it = lista_.begin(); it != lista_.end(); it++) {
      Pessoa p;
      p.nome = it->nome;
      p.prioridade = it->prioridade;
      pessoas.push_back(p);
    }

    // ordena o vetor auxiliar por ordem decrescente de prioridade
    sort(pessoas.begin(), pessoas.end(), [](const Pessoa& a, const Pessoa& b) {
      return a.prioridade > b.prioridade;
    });

    // extrai apenas os nomes das pessoas do vetor ordenado
    for (const auto& p : pessoas) {
      nomes.push_back(p.nome);
    }

    return nomes;
}
