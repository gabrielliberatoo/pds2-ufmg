#ifndef __DICIONARIO_H__
#define __DICIONARIO_H__

#include <list>
#include <string>
#include <iostream>
#include <exception>

using std::list;
using std::string;
using namespace std;

// Exceção que indica que o dicionário está vazio.
class excecaoDicionarioVazio{
   public:
   excecaoDicionarioVazio();
   void msg1();
   private:
   string frase;
};

/*class DicionarioVazio : public std::exception {
public:
    const char* what() const noexcept override {
        return "Dicionário vazio.";
    }
};*/

// Exceção que indica que uma determinada chave não está no dicionário.
class naoContemChave{
    public:
    naoContemChave(string chavechave);
    void msg2(string chave);

    private:
    string chave;
};

// Exceção que indica que uma determinada chave já se encontra no dicionário.
class contemChave{
    public:
    contemChave(string chave);
    void msg3(string chave);

    private:
    string chave;
};

// Implementa um dicionário que mapeia uma chave (do tipo string)
// a um valor (também do tipo string).
// As chaves são únicas, e estão dispostas em qualquer ordem na lista. 
class Dicionario {
 public:
  // Cria um dicionário vazio.
  Dicionario();

  // Retorna quantos pares chave/valor estão no dicionário.
  int tamanho();

  // Testa se uma chave pertence ao dicionário.
  bool pertence(string chave);

  // Retorna a *menor* chave do dicionário.
  // Pré-condição: o dicionário não está vazio.
  string menor();

  // Retorna o valor associado a chave.
  // Pré-condição: a chave *necessariamente* está no dicionário.
  string valor(string chave);

  // Insere um par chave/valor no dicionário.
  // Pré-condição: a chave *não* está no dicionário.
  void Inserir(string chave, string valor);

  // Remove um par chave/valor do dicionário.
  // Pré-condição: a chave *necessariamente* está no dicionário.
  void Remover(string chave);

  // Altera o valor associado a uma chave do dicionário.
  // Pré-condição: a chave *necessariamente* está no dicionário.
  void Alterar(string chave, string valor);

  // Libera toda a memória alocada para armazenar os dados no
  // dicionário.
  ~Dicionario();
 private:
  struct Elemento {
    string chave; // Identificar do elemento.
    string valor; // Valor associado ao elemento.
  };
  // Lista de elementos, ou seja, lista de pares chave/valor.
  list<Elemento> elementos_;
};
#endif // __DICIONARIO_H__