#include "jogo_da_vida.h"

JogoDaVida::JogoDaVida(int l, int c) {
  vivas_ = std::vector<std::vector<bool>>(l, std::vector<bool>(c, false));
}

bool JogoDaVida::viva(int i, int j) {
  return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j) {
  vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j) {
  if (i < 0 || i >= linhas() || j < 0 || j >= colunas()) {
    throw ExcecaoCelulaInvalida{i, j};
  }
  vivas_[i][j] = true;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
  int count = 0;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (i == 0 && j == 0) continue;

      int nx = (x + i + linhas()) % linhas();
      int ny = (y + j + colunas()) % colunas();

      if (viva(nx, ny)) {
        count++;
      }
    }
  }
  return count;
}

void JogoDaVida::ExecutarProximaIteracao() {
  std::vector<std::vector<bool>> proximo(linhas(), std::vector<bool>(colunas(), false));

  for (int i = 0; i < linhas(); ++i) {
    for (int j = 0; j < colunas(); ++j) {
      int vizinhas_vivas = NumeroDeVizinhasVivas(i, j);
      bool atual = viva(i, j);

      if (atual && (vizinhas_vivas == 2 || vizinhas_vivas == 3)) {
        proximo[i][j] = true; // Célula sobrevive
      } else if (!atual && vizinhas_vivas == 3) {
        proximo[i][j] = true; // Célula nasce
      } else {
        proximo[i][j] = false; // Célula morre
      }
    }
  }

  vivas_ = proximo;
}

void JogoDaVida::Executar(int n) {
  for (int i = 0; i < n; ++i) {
    ExecutarProximaIteracao();
  }
}
