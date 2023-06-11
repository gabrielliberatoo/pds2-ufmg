#include "jogo_da_vida.h"

JogoDaVida::JogoDaVida(int l, int c) {
  // Inicializa todas as células como mortas.
  vivas_.resize(l, std::vector<bool>(c, false));
}

bool JogoDaVida::viva(int i, int j) {
  return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j) {
  vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j) {
  vivas_[i][j] = true;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
  int count = 0;
  int linhas = vivas_.size();
  int colunas = vivas_[0].size();

  // Verifica as células vizinhas.
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) continue; // Ignora a célula atual.
      int nx = (x + i + linhas) % linhas;  // Lógica do toro.
      int ny = (y + j + colunas) % colunas;  // Lógica do toro.
      if (vivas_[nx][ny]) count++;
    }
  }

  return count;
}

void JogoDaVida::ExecutarProximaIteracao() {
  int linhas = vivas_.size();
  int colunas = vivas_[0].size();

  // Cria uma cópia temporária das células vivas.
  std::vector<std::vector<bool>> proxima_iteracao = vivas_;

  // Atualiza o estado das células na próxima iteração.
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      int vizinhas_vivas = NumeroDeVizinhasVivas(i, j);

      if (vivas_[i][j]) {
        // Celula viva:
        // Morre de solidão ou superpopulação.
        if (vizinhas_vivas <= 1 || vizinhas_vivas > 3) {
          proxima_iteracao[i][j] = false;
        }
      } else {
        // Celula morta:
        // Nasce se tem exatamente 3 vizinhas vivas.
        if (vizinhas_vivas == 3) {
          proxima_iteracao[i][j] = true;
        }
      }
    }
  }

  // Atualiza o estado do jogo para a próxima iteração.
  vivas_ = proxima_iteracao;
}
