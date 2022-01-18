
#include <stdio.h>
#include <stdlib.h>
#include "FilaTexto.h"

FilaTexto * criar_fila() {
  FilaTexto *f = malloc(sizeof(FilaTexto));

  if (f == NULL) {
    return NULL;
  }

  f->ini = f->fim = NULL;
  f->qt = 0;

  return f;
}

void destruir_fila(FilaTexto *f) {
  while(!fila_vazia(f)) {
    remover_fila(f);
  }

  free(f);
}

int inserir_fila(FilaTexto *f, char *texto) {
  // criar um novo nó
  No *novo_no = malloc(sizeof(No));

  if (novo_no == NULL) {
    return -1;
  }

  novo_no->texto = texto;
  novo_no->prox = NULL;

  if (fila_vazia(f)) {
    // nó único é o ini e fim
    f->ini = f->fim = novo_no;
  } else {
    // ref do último nó da fila
    No *ultimo = f->fim;

    // anexa o novo nó ao final da fila
    ultimo->prox = novo_no;

    // o novo fim da fila é o novo nó
    f->fim = novo_no;
  }

  f->qt++;

  return 0;
}

char *remover_fila(FilaTexto *f) {
  No *primeiro;
  char *result;

  if (fila_vazia(f)) {
    return NULL;
  }

  // ref do primeiro - que vai ser rmovido
  primeiro = f->ini;
  
  // salva a ref do texto do primeiro nó em result
  result = primeiro->texto;

  // o inicio da fila agora é o "segundo"
  f->ini = primeiro->prox;

  // se eu reemovi todos os elementos...
  if (f->ini == NULL) {
    f->fim = NULL;
  }

  // agora pode destruir o primeiro
  free(primeiro);

  f->qt--;

  return result;
}

int fila_vazia(FilaTexto *f) {
  if (f->ini == NULL && f->fim == NULL) {
    return TRUE;
  }

  return FALSE;
}

void imprimir_fila(FilaTexto *f) {
  No *atual = f->ini;
  
  printf("ini [");

  // enquanto eu não cheguei no final da fila
  while (atual != NULL) {
    printf(" (%s) ", atual->texto);

    atual = atual->prox;
  }

  printf(" ] fim\n");
}