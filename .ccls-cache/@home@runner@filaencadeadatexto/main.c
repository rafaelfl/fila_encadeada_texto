#include <stdio.h>
#include "FilaTexto.h"

int main(void) {
  FilaTexto *f = criar_fila();

  inserir_fila(f, "WandaVision");
  inserir_fila(f, "Falcão e Soldado Invernal");
  inserir_fila(f, "Loki");
  inserir_fila(f, "Hawkeye");
  inserir_fila(f, "Eternos");

  imprimir_fila(f);

  remover_fila(f);
  remover_fila(f);
  remover_fila(f);

  imprimir_fila(f);

  inserir_fila(f, "Shang Chi");
  inserir_fila(f, "Spider man No Way Home");

  imprimir_fila(f);

  remover_fila(f);
  remover_fila(f);
  remover_fila(f);
  remover_fila(f);
  remover_fila(f);
  remover_fila(f);
  
  imprimir_fila(f);

  destruir_fila(f);
  
  return 0;
}