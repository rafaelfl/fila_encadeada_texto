
#define TRUE 1
#define FALSE 0

typedef struct _no {
  char *texto;
  struct _no *prox;
} No;

typedef struct _fila {
  No *ini, *fim;
  int qt;
} FilaTexto;

FilaTexto * criar_fila();
void destruir_fila(FilaTexto *f);
int inserir_fila(FilaTexto *f, char *texto);
char *remover_fila(FilaTexto *f);
int fila_vazia(FilaTexto *f);
void imprimir_fila(FilaTexto *f);
