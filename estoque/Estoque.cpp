#include "Estoque.hpp"
#include <iostream>

void Estoque::add_mercadoria(const std::string& s, unsigned int qtd) {
    estoque[s] += qtd;
}

unsigned int Estoque::get_qtd(const std::string& s) const {
    auto it = estoque.find(s);
    if (it != estoque.end()) {
        return it->second;
    }
    return 0;
}

void Estoque::sub_mercadoria(const std::string& s, unsigned int qtd) {
    auto it = estoque.find(s);
    if (it != estoque.end()) {
        if (it->second < qtd) {
            std::cout << s << " insuficiente" << std::endl;
        } else {
            it->second -= qtd;
        }
    } else {
        std::cout << s << " inexistente" << std::endl;
    }
}

void Estoque::imprime_estoque() const {
    for (const auto& item : estoque) {
        std::cout << item.first << ": " << item.second << std::endl;
    }
}

Estoque& Estoque::operator+=(const Estoque& rhs) {
    for (const auto& item : rhs.estoque) {
        estoque[item.first] += item.second;
    }
    return *this;
}

Estoque& Estoque::operator-=(const Estoque& rhs) {
    for (const auto& item : rhs.estoque) {
        auto it = estoque.find(item.first);
        if (it != estoque.end()) {
            if (it->second < item.second) {
                std::cout << item.first << " insuficiente" << std::endl;
            } else {
                it->second -= item.second;
            }
        } else {
            std::cout << item.first << " inexistente" << std::endl;
        }
    }
    return *this;
}

bool operator<(const Estoque& e0, const Estoque& e1) {
  return e0.estoque < e1.estoque;
}

bool operator>(const Estoque& e0, const Estoque& e1) {
  return e0.estoque > e1.estoque;
}


