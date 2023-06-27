#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <string>
#include <map>

class Estoque {
public:
    void add_mercadoria(const std::string& s, unsigned int qtd);
    unsigned int get_qtd(const std::string& s) const;
    void sub_mercadoria(const std::string& s, unsigned int qtd);
    void imprime_estoque() const;
    Estoque& operator+=(const Estoque& rhs);
    Estoque& operator-=(const Estoque& rhs);
    friend bool operator<(const Estoque& e0, const Estoque& e1);
    friend bool operator>(const Estoque& e0, const Estoque& e1);

private:
    std::map<std::string, unsigned int> estoque;
};

#endif  // ESTOQUE_HPP
